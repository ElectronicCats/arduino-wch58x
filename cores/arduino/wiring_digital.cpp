/*
  wiring_digital.cpp - digital input and output functions
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
#include "CH58x_gpio.h"

void pinMode(pin_size_t pin, PinMode mode)
{
  GPIOModeTypeDef pinConfig; 
  switch (mode) {
    case INPUT:
      pinConfig=GPIO_ModeIN_Floating;
      break;
    case OUTPUT:
      pinConfig=GPIO_ModeOut_PP_20mA;
      break;
    case INPUT_PULLUP:
      pinConfig=GPIO_ModeIN_PU;
      break;
    case INPUT_PULLDOWN:
    default:
      pinConfig=GPIO_ModeIN_PD;
      break;
  }

  if (pin <16){
  GPIOA_ModeCfg(1 << (pin),pinConfig);
  }
  else{
  GPIOB_ModeCfg(1 << (pin - 16),pinConfig);
  }
}


void digitalWrite(pin_size_t pin, PinStatus val)
{
  if (pin <16){
  if(val){
    GPIOA_SetBits(1 << (pin));
  }
  else{
   GPIOA_ResetBits(1 << (pin));
    }
  }
  
  else{
    if(val){
    GPIOB_SetBits(1 << (pin - 16));
  }
  else{
   GPIOB_ResetBits(1 << (pin  - 16));
    } 
  }
}

PinStatus digitalRead(pin_size_t pin)
{

  if (pin <16){
    return (PinStatus)GPIOA_ReadPortPin(1 << (pin)); 
  }
else{
    return (PinStatus)GPIOB_ReadPortPin(1 << (pin - 16));
} 
}