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
  int channel = 0;
  GPIOA_ModeCfg(1 << (pin), GPIO_ModeIN_Floating);
  ADC_ExtSingleChSampInit(SampleFreq_3_2, ADC_PGA_0);
  if((pin == 4) || (pin ==  5)){
    channel = pin - 4;
    //ADC_ChannelCfg(channel);
   }
  if((pin == 6) || (pin == 7) || (pin == 8) || (pin == 9) ){
    channel = pin + 4;
    //ADC_ChannelCfg(channel);
  }
  if( (pin > 11) && (pin <16)){
    channel = pin - 10;
    //ADC_ChannelCfg(channel);
  }
  if( (pin >= 0) && (pin < 4)){
    channel = 9-pin;
    //ADC_ChannelCfg(channel);
  }
    uint16_t i;
    uint32_t sum = 0;
    uint8_t  ch = 0;   // ����ͨ��
    uint8_t  ctrl = 0; // ���ݿ��ƼĴ���

    ch = R8_ADC_CHANNEL;
    ctrl = R8_ADC_CFG;
    R8_ADC_CFG = 0;

    ADC_ChannelCfg(channel);                                          // ADCУ׼ͨ����ѡ��ͨ��1
    R8_ADC_CFG |= RB_ADC_OFS_TEST | RB_ADC_POWER_ON | (2 << 4); // �������ģʽ
    R8_ADC_CONVERT = RB_ADC_START;
    while(R8_ADC_CONVERT & RB_ADC_START);
    for(i = 0; i < 16; i++)
    {
        R8_ADC_CONVERT = RB_ADC_START;
        while(R8_ADC_CONVERT & RB_ADC_START);
        sum += (~R16_ADC_DATA) & RB_ADC_DATA;
    }
    sum = (sum + 8) >> 4;
    R8_ADC_CFG &= ~RB_ADC_OFS_TEST; // �رղ���ģʽ

    R8_ADC_CHANNEL = ch;
    R8_ADC_CFG = ctrl;
   
  return ADC_ExcutSingleConver() + (2024 - sum);   // 2048
  
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