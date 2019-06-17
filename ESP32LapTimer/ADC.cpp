////Functions to Read RSSI from ADCs//////
#include <driver/adc.h>
#include <driver/timer.h>
#include <esp_adc_cal.h>

#include <Wire.h>
#include <Adafruit_INA219.h>

#include "HardwareConfig.h"
#include "Comms.h"
#include "settings_eeprom.h"
#include "ADC.h"
#include "Timer.h"
#include "UDP.h"
#include "Calibration.h"
#include "Laptime.h"
#include "Utils.h"
#include "RX5808.h"

static Timer ina219Timer = Timer(1000);

static Adafruit_INA219 ina219; // A0+A1=GND

static uint32_t LastADCcall;

static esp_adc_cal_characteristics_t adc_chars;

static int RSSIthresholds[MaxNumRecievers];
static uint16_t ADCReadingsRAW[MaxNumRecievers];
static unsigned int VbatReadingSmooth;
static int ADCvalues[MaxNumRecievers];
static uint16_t adcLoopCounter = 0;

static FilterBeLp2_10HZ Filter_10HZ[6] = {FilterBeLp2_10HZ(), FilterBeLp2_10HZ(), FilterBeLp2_10HZ(), FilterBeLp2_10HZ(), FilterBeLp2_10HZ(), FilterBeLp2_10HZ()};
static FilterBeLp2_20HZ Filter_20HZ[6] = {FilterBeLp2_20HZ(), FilterBeLp2_20HZ(), FilterBeLp2_20HZ(), FilterBeLp2_20HZ(), FilterBeLp2_20HZ(), FilterBeLp2_20HZ()};
static FilterBeLp2_50HZ Filter_50HZ[6] = {FilterBeLp2_50HZ(), FilterBeLp2_50HZ(), FilterBeLp2_50HZ(), FilterBeLp2_50HZ(), FilterBeLp2_50HZ(), FilterBeLp2_50HZ()};
static FilterBeLp2_100HZ Filter_100HZ[6] = {FilterBeLp2_100HZ(), FilterBeLp2_100HZ(), FilterBeLp2_100HZ(), FilterBeLp2_100HZ(), FilterBeLp2_100HZ(), FilterBeLp2_100HZ()};

static float VBATcalibration;
static float mAReadingFloat;
static float VbatReadingFloat;

static uint8_t active_pilots[MaxNumRecievers];
static uint8_t current_pilot_num = 0;

// TODO: change for multiple modules. assign each module a current pilot?
static uint8_t getNextPilot(uint8_t current_pilot) {
	for(uint8_t i = 1; i < MaxNumRecievers + 1; ++i) {
		uint8_t next_pilot = (current_pilot + i) % MaxNumRecievers;
		if(active_pilots[next_pilot] == 1) {
			return next_pilot;
		}
	}
	return current_pilot;
}

void ConfigureADC() {

  adc1_config_width(ADC_WIDTH_BIT_12);

  adc1_config_channel_atten(ADC1, ADC_ATTEN_6db);
  adc1_config_channel_atten(ADC2, ADC_ATTEN_6db);
  adc1_config_channel_atten(ADC3, ADC_ATTEN_6db);
  adc1_config_channel_atten(ADC4, ADC_ATTEN_6db);
  adc1_config_channel_atten(ADC5, ADC_ATTEN_6db);
  adc1_config_channel_atten(ADC6, ADC_ATTEN_6db);

  //since the reference voltage can range from 1000mV to 1200mV we are using 1100mV as a default
  esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_6db, ADC_WIDTH_BIT_12, 1100, &adc_chars);

  ina219.begin();
  ReadVBAT_INA219();
}

void IRAM_ATTR nbADCread( void * pvParameters ) {
	static uint8_t current_adc = 0;
	static uint32_t last_hop = 0;
	static uint8_t current_pilot = 0;
	
	if(current_adc == 0) ++adcLoopCounter;

	//xSemaphoreTake( xBinarySemaphore, portMAX_DELAY );
	uint32_t now = micros();
	LastADCcall = now;
	adc1_channel_t channel = ADC1;
	switch (current_adc) {
		case 0:
		channel = ADC1;
		break;
		case 1:
		channel = ADC2;
		break;
		case 2:
		channel = ADC3;
		break;
		case 3:
		channel = ADC4;
		break;
		case 4:
		channel = ADC5;
		break;
		case 5:
		channel = ADC6;
		break;
	}
	if(current_pilot_num > NUM_PHYSICAL_RECEIVERS) {
		if(now - last_hop > MULTIPLEX_STAY_TIME_US) {
			// TODO: save pilot status of every pilot
			current_pilot = getNextPilot(current_pilot);
			// TODO: support multiple modules
			// TODO: add class between this and rx5808
			// TODO: add better multiplexing. Maybe based on the last laptime?
			// TODO: add smarter jumping with multiple modules available
			setModuleChannelBand(getRXChannelPilot(current_pilot), getRXBandPilot(current_pilot), current_adc);
			last_hop = now;
			Serial.print("Current Pilot: ");
			Serial.println(current_pilot);
		}
	} else { // only a single pilot
		current_pilot = getNextPilot(current_pilot);
	}
	
	ADCReadingsRAW[current_pilot] = adc1_get_raw(channel);

	// Applying calibration
	if (LIKELY(!isCalibrating())) {
		// skip if voltage is on this channel
		if(!(getADCVBATmode() == ADC_CH5 && current_adc == 4) || (getADCVBATmode() == ADC_CH6 && current_adc == 5)) {
			uint16_t rawRSSI = constrain(ADCReadingsRAW[current_pilot], EepromSettings.RxCalibrationMin[current_adc], EepromSettings.RxCalibrationMax[current_adc]);
			ADCReadingsRAW[current_pilot] = map(rawRSSI, EepromSettings.RxCalibrationMin[current_adc], EepromSettings.RxCalibrationMax[current_adc], 800, 2700); // 800 and 2700 are about average min max raw values
		} 
	}

	/*switch (getRXADCfilter()) {

		case LPF_10Hz:
			ADCvalues[current_pilot] = Filter_10HZ[current_pilot].step(ADCReadingsRAW[current_pilot]);
			break;

		case LPF_20Hz:
			ADCvalues[current_pilot] = Filter_20HZ[current_pilot].step(ADCReadingsRAW[current_pilot]);
			break;

		case LPF_50Hz:
			ADCvalues[current_pilot] = Filter_50HZ[current_pilot].step(ADCReadingsRAW[current_pilot]);
			break;

		case LPF_100Hz:
			ADCvalues[current_pilot] = Filter_100HZ[current_pilot].step(ADCReadingsRAW[current_pilot]);
			break;
	}*/
	
	ADCvalues[current_pilot] = ADCReadingsRAW[current_pilot];

	switch (getADCVBATmode()) {
		case ADC_CH5:
			VbatReadingSmooth = esp_adc_cal_raw_to_voltage(ADCvalues[4], &adc_chars);
			setVbatFloat(VbatReadingSmooth / 1000.0 * VBATcalibration);
			break;
		case ADC_CH6:
			VbatReadingSmooth = esp_adc_cal_raw_to_voltage(ADCvalues[5], &adc_chars);
			setVbatFloat(VbatReadingSmooth / 1000.0 * VBATcalibration);
			break;
		default:
			break;
	}

	if (LIKELY(isInRaceMode() > 0)) {
		CheckRSSIthresholdExceeded(current_pilot);
	}
	current_adc = (current_adc + 1) % NUM_PHYSICAL_RECEIVERS;
}


void ReadVBAT_INA219() {
  if (ina219Timer.hasTicked()) {
    setVbatFloat(ina219.getBusVoltage_V() + (ina219.getShuntVoltage_mV() / 1000));
    mAReadingFloat = ina219.getCurrent_mA();
    ina219Timer.reset();
  }
}

void IRAM_ATTR CheckRSSIthresholdExceeded(uint8_t node) {
	uint32_t CurrTime = millis();
	if ( ADCvalues[node] > RSSIthresholds[node]) {
		if (CurrTime > (getMinLapTime() + getLaptime(node))) {
			uint8_t lap_num = addLap(node, CurrTime);
			sendLap(lap_num, node);
		}
	}
}

uint16_t getRSSI(uint8_t index) {
  if(index < MaxNumRecievers) {
    return ADCvalues[index];  
  }
  return 0;
}

void updatePilotNumbers() {
	memset(active_pilots, 1, MaxNumRecievers);
	current_pilot_num = MaxNumRecievers;
	for(uint8_t i = 0; i < MaxNumRecievers; ++i) {
		if(RSSIthresholds[i] == 0) {
			active_pilots[i] = 0;
			// Set adc values to 0 for display etc
			ADCvalues[i] = 0;
			ADCReadingsRAW[i] = 0;
			--current_pilot_num;
		}
	}
	Serial.print("New pilot num: ");
	Serial.println(current_pilot_num);
}

void setRSSIThreshold(uint8_t node, uint16_t threshold) {
  if(node < MaxNumRecievers) {
    RSSIthresholds[node] = threshold;
    updatePilotNumbers();
  }
}

uint16_t getRSSIThreshold(uint8_t node){
	return RSSIthresholds[node];
}

uint16_t getADCLoopCount() {
	return adcLoopCounter;
}

void setADCLoopCount(uint16_t count) {
	adcLoopCounter = count;
}

void setVbatCal(float calibration) {
	VBATcalibration = calibration;
}

float getMaFloat() {
	return mAReadingFloat;
}

float getVbatFloat(){
	return VbatReadingFloat;
}

void setVbatFloat(float val){
	VbatReadingFloat = val;
}

void setVBATcalibration(float val) {
	VBATcalibration = val;
}

float getVBATcalibration() {
	return VBATcalibration;
}
