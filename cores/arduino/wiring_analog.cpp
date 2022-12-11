/*
  wiring_analog.cpp - analog input and output functions
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2018-2019 Arduino SA

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#include "Arduino.h"
#include "CH58x_common.h"

static int write_resolution = 8;
static int read_resolution = 10;

#if DEVICE_ANALOGOUT

void analogWriteDAC(pin_size_t pin, int val) {
 
}
#endif

void analogWrite(pin_size_t pin, int val)
{
  GPIOA_ModeCfg(1 << (pin), GPIO_ModeOut_PP_5mA);
  PWMX_CLKCfg(4);                                   // cycle = 4/Fsys
  PWMX_CycleCfg(PWMX_Cycle_64);                     // ���� = 64*cycle
  PWMX_ACTOUT(CH_PWM4, 64 / 4, Low_Level, ENABLE);  //
}

void analogWriteResolution(int bits)
{

}

int analogRead(pin_size_t pin)
{
  GPIOA_ModeCfg(1 << (pin), GPIO_ModeIN_Floating);
  ADC_ExtSingleChSampInit(SampleFreq_3_2, ADC_PGA_0);
  ADC_ChannelCfg(0);
  return ADC_ExcutSingleConver() + ADC_DataCalib_Rough();
  
}

#ifdef ANALOG_CONFIG
/* Spot all active ADCs to reconfigure them */
void analogUpdate() 
{
  isAdcConfigChanged = true;
  //for (pin_size_t i = A0; i < A0 + NUM_ANALOG_INPUTS; i++) {  //also the other works
  for (pin_size_t i = 0; i < NUM_ANALOG_INPUTS; i++) {
    if (analogPinToAdcObj(i) != NULL) {
      analogPinToAdcObj(i)->configure(adcCurrentConfig);
    }
  }
}
#endif

void analogReadResolution(int bits)
{
  read_resolution = bits;
}

int getAnalogReadResolution()
{
  return read_resolution;
}