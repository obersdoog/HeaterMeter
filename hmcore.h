#ifndef __HMCORE_H__
#define __HMCORE_H__

#define HEATERMETER_NETWORKING  // enable wifi interface
//#define HEATERMETER_SERIAL      // enable serial notifications

#include "grillpid.h"
#include "hmmenus.h"
#include "flashfiles.h"

// Analog Pins
#define PIN_PIT     5
#define PIN_FOOD1   4
#define PIN_FOOD2   3
#define PIN_AMB     2
#define PIN_BUTTONS 0
// Digital Output Pins
#define PIN_SERIALRX     0  // Can not be changed
#define PIN_SERIALTX     1  // Can not be changed
#define PIN_WIFI_INT     2
#define PIN_BLOWER       3
#define PIN_LCD_CLK      4
#define PIN_ALARM        5
#define PIN_DATAFLASH_SS 7
#define PIN_LCD_DATA     8
#define PIN_WIFI_SS     10
#define PIN_SPI_MOSI    11  // Can not be changed
#define PIN_SPI_MISO    12  // Can not be changed
#define PIN_SPI_SCK     13  // Can not be changed

const struct steinhart_param STEINHART[] = {
  {2.3067434e-4f, 2.3696596e-4f, 1.2636414e-7f},  // Maverick Probe
  // {8.98053228e-4f, 2.49263324e-4f, 2.04047542e-7f}, // Radio Shack 10k
  {1.1415e-3f, 2.31905e-4f, 9.76423e-8f} // Vishay 10k NTCLE100E3103JB0
};

//#define USE_EXTERNAL_VREF  // uncomment if using external 5V as input to analog inputs

void hmcoreSetup(void);
void hmcoreLoop(void);

void updateDisplay(void);
void lcdprint_P(const prog_char *p, const boolean doClear);

void eepromLoadConfig(boolean forceDefault);
void storeSetPoint(int sp);
boolean storeProbeName(unsigned char probeIndex, const char *name);
void loadProbeName(unsigned char probeIndex);
boolean storeProbeOffset(unsigned char probeIndex, char offset);
void storeProbeAlarmOn(unsigned char probeIndex, boolean isHigh, boolean value);
void storeProbeAlarmVal(unsigned char probeIndex, boolean isHigh, int value);
boolean storePidParam(char which, float value);
void storeMaxFanSpeed(unsigned char maxFanSpeed);
void storeLidOpenOffset(unsigned char value);
void storeLidOpenDuration(unsigned int value);

extern GrillPid pid;

#endif /* __HMCORE_H__ */
