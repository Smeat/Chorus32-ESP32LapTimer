/*
 * This file is part of Chorus32-ESP32LapTimer 
 * (see https://github.com/AlessandroAU/Chorus32-ESP32LapTimer).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef HEADER_RX5808
#define HEADER_RX5808

#include <stdint.h>

#include <Arduino.h>

#define MAX_BAND 7

//// Channels to send to the SPI registers
//const uint16_t channelTable[] PROGMEM = {
//  // Channel 1 - 8
//  0x281D, 0x288F, 0x2902, 0x2914, 0x2987, 0x2999, 0x2A0C, 0x2A1E, // Raceband
//  0x2A05, 0x299B, 0x2991, 0x2987, 0x291D, 0x2913, 0x2909, 0x289F, // Band A
//  0x2903, 0x290C, 0x2916, 0x291F, 0x2989, 0x2992, 0x299C, 0x2A05, // Band B
//  0x2895, 0x288B, 0x2881, 0x2817, 0x2A0F, 0x2A19, 0x2A83, 0x2A8D, // Band E
//  0x2906, 0x2910, 0x291A, 0x2984, 0x298E, 0x2998, 0x2A02, 0x2A0C, // Band F / Airwave
//  0x2609, 0x261C, 0x268E, 0x2701, 0x2713, 0x2786, 0x2798, 0x280B, // Band D / 5.3
//  0x248f, 0x2499, 0x2503, 0x250d, 0x2909, 0x2913, 0x291d, 0x2987, //connex
//  0x2991, 0x299b, 0x299b, 0x299b, 0x299b, 0x299b, 0x299b, 0x299b  //even more connex, last 6 unused!!!
//};
//
//// Channels' MHz Values. Just for reference. Not used in code.

const uint16_t channelFreqTable[] = {
  //     // Channel 1 - 8
  5658, 5695, 5732, 5769, 5806, 5843, 5880, 5917, // Raceband
  5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725, // Band A
  5733, 5752, 5771, 5790, 5809, 5828, 5847, 5866, // Band B
  5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945, // Band E
  5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880, // Band F / Airwave
  5362, 5399, 5436, 5473, 5510, 5547, 5584, 5621, // Band D / 5.3
  5180, 5200, 5220, 5240, 5745, 5765, 5785, 5805, // connex
  5825, 5845, 5845, 5845, 5845, 5845, 5845, 5845  // even more connex, last 6 unused!!!
};

//uint16_t BandChannelFreqTable[8][8] = {
//  //     // Channel 1 - 8
//  {5658, 5695, 5732, 5769, 5806, 5843, 5880, 5917}, // Raceband
//  {5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725}, // Band A
//  {5733, 5752, 5771, 5790, 5809, 5828, 5847, 5866}, // Band B
//  {5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945}, // Band E
//  {5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880}, // Band F / Airwave
//  {5362, 5399, 5436, 5473, 5510, 5547, 5584, 5621}, // Band D / 5.3
//  {5180, 5200, 5220, 5240, 5745, 5765, 5785, 5805}, // connex
//  {5825, 5845, 5845, 5845, 5845, 5845, 5845, 5845}
//  // even more connex, last 6 unused!!!
//};


void InitSPI();
void SetDefaultRegs();
uint16_t setModuleChannelBand(uint8_t NodeAddr);
uint16_t setModuleChannelBand(uint8_t channel, uint8_t band, uint8_t NodeAddr);
uint16_t setModuleFrequencyAll(uint16_t frequency);
uint16_t setModuleFrequency(uint16_t frequency, uint8_t NodeAddr);
String getBandLabel(int band);

void setRXBandModule(uint8_t module, uint8_t band);
uint8_t getRXBandModule(uint8_t module);

void setRXChannelModule(uint8_t module, uint8_t channel);
uint8_t getRXChannelModule(uint8_t module);

void setRXBandPilot(uint8_t pilot, uint8_t band);
uint8_t getRXBandPilot(uint8_t pilot);

void setRXChannelPilot(uint8_t pilot, uint8_t channel);
uint8_t getRXChannelPilot(uint8_t pilot);

uint16_t getFrequencyFromBandChannel(uint8_t band, uint8_t channel);

bool isRxReady(uint8_t module);

void RXpowerOn(uint8_t NodeAddr);
void RXstandBy(uint8_t NodeAddr);
void RXPowerDown(uint8_t NodeAddr);
void RXreset(uint8_t NodeAddr);
void RXstandBy(uint8_t NodeAddr);
void RXPowerUpAll();
void RXPowerDownAll();
void RXResetAll();
void rxLowPower(uint8_t node);
void rxLowPowerAll();

#endif
