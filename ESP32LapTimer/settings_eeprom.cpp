#include <EEPROM.h>
#include "settings_eeprom.h"
#include "Comms.h"
#include "RX5808.h"
#include "crc.h"

struct EepromSettingsStruct EepromSettings;

static bool eepromSaveRequired = false;

void EepromSettingsStruct::setup() {
  EEPROM.begin(512);
  this->load();
}

void EepromSettingsStruct::load() {
  EEPROM.get(0, *this);
  Serial.println("EEPROM LOADED");

  if (this->eepromVersionNumber != EEPROM_VERSION_NUMBER) {
    this->defaults();
    Serial.println("EEPROM DEFAULTS LOADED");
  }
}

bool EepromSettingsStruct::SanityCheck() {

  bool IsGoodEEPROM = true;

  if (EepromSettings.NumReceivers > MAX_NUM_RECEIVERS) {
    IsGoodEEPROM = false;
    Serial.print("Error: Corrupted EEPROM value getNumReceivers(): ");
    Serial.println(EepromSettings.NumReceivers);
  }

  if (EepromSettings.ADCVBATmode > MaxVbatMode) {
    IsGoodEEPROM = false;
    Serial.print("Error: Corrupted EEPROM value ADCVBATmode: ");
    Serial.println(EepromSettings.ADCVBATmode);
  }

  if (EepromSettings.VBATcalibration > MaxVBATCalibration) {
    IsGoodEEPROM = false;
    Serial.print("Error: Corrupted EEPROM value VBATcalibration: ");
    Serial.println(EepromSettings.VBATcalibration);
  }

  for (int i = 0; i < MAX_NUM_PILOTS; i++) {
    if (EepromSettings.RXBand[i] > MaxBand) {
      IsGoodEEPROM = false;
      Serial.print("Error: Corrupted EEPROM NODE: ");
      Serial.print(i);
      Serial.print(" value MaxBand: ");
      Serial.println(EepromSettings.RXBand[i]);
    }

  }

  for (int i = 0; i < MAX_NUM_PILOTS; i++) {
    if (EepromSettings.RXChannel[i] > MaxChannel) {
      IsGoodEEPROM = false;
      Serial.print("Error: Corrupted EEPROM NODE: ");
      Serial.print(i);
      Serial.print(" value RXChannel: ");
      Serial.println(EepromSettings.RXChannel[i]);
    }
  }

  for (int i = 0; i < MAX_NUM_PILOTS; i++) {
    if (EepromSettings.RSSIthresholds[i] > MaxThreshold) {
      IsGoodEEPROM = false;
      Serial.print("Error: Corrupted EEPROM NODE: ");
      Serial.print(i);
      Serial.print(" value RSSIthresholds: ");
      Serial.println(EepromSettings.RSSIthresholds[i]);
    }
  }
  return IsGoodEEPROM && this->validateCRC();
}

void EepromSettingsStruct::save() {
  if (eepromSaveRequired) {
  this->updateCRC();
    EEPROM.put(0, *this);
    EEPROM.commit();
    eepromSaveRequired = false;
    Serial.println("EEPROM SAVED");
  }
}

void EepromSettingsStruct::defaults() {
  // We are using a temporary struct since we might have invalid values during setup and core 0 might use them
  EepromSettingsStruct settings;
  // by setting everything to 0 we guarantee that every variable is initialized
  memset(&settings, 0, sizeof(EepromSettingsStruct));
  for(uint8_t i = 0; i < MAX_NUM_RECEIVERS; ++i){
    settings.RxCalibrationMax[i] = 2700;
    settings.RxCalibrationMin[i] = 800;
  }
  for(uint8_t i = 0; i < MAX_NUM_PILOTS; ++i){
    settings.RSSIthresholds[i] = 2048;
    settings.RXBand[i] = 0;
    settings.RXChannel[i] = i % 8;
  }

  settings.eepromVersionNumber = EEPROM_VERSION_NUMBER;
  settings.ADCVBATmode = INA219;
  settings.RXADCfilterCutoff = 20;
  settings.VBATcalibration = 1;
  settings.NumReceivers = 6;
  settings.WiFiProtocol = 1;
  settings.WiFiChannel = 1;
  settings.screen_timeout_ms = 2000;
  this->min_voltage_module = EEPROM_DEFAULT_MIN_VOLTAGE_MODULE;

  settings.updateCRC();

  *this = settings;

  EEPROM.put(0, *this);
  EEPROM.commit();
}

crc_t EepromSettingsStruct::calcCRC() {
  crc_t crc = crc_init();
  crc = crc_update(crc, this, sizeof(*this) - sizeof(this->crc));
  crc = crc_finalize(crc);
  return crc;
}

void EepromSettingsStruct::updateCRC() {
  this->crc = this->calcCRC();
}

bool EepromSettingsStruct::validateCRC(){
  return this->crc == this->calcCRC();
}


uint16_t getRXADCfilterCutoff() {
  return EepromSettings.RXADCfilterCutoff;
}

ADCVBATmode_ getADCVBATmode() {
  return EepromSettings.ADCVBATmode;
}

void setRXADCfilterCutoff(uint16_t cutoff) {
  EepromSettings.RXADCfilterCutoff = cutoff;
}

void setADCVBATmode(ADCVBATmode_ mode) {
  EepromSettings.ADCVBATmode = mode;
}

void setSaveRequired() {
  eepromSaveRequired = true;
}

int getWiFiChannel(){
  return EepromSettings.WiFiChannel;
}
int getWiFiProtocol(){
  return EepromSettings.WiFiProtocol;
}

uint8_t getNumReceivers() {
  return EepromSettings.NumReceivers;
}

uint16_t getMinVoltageModule() {
  return EepromSettings.min_voltage_module;
}

uint16_t getFilterCutoff() {
  return EepromSettings.RXADCfilterCutoff;
}

uint32_t getScreenTimeout() {
  return EepromSettings.screen_timeout_ms;
}
