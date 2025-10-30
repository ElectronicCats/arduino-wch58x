# Arduino-WCH58x

Arduino core for the CH58x

## Overview

The CH58x is a 32-bit RISC microcontroller integrated with BLE wireless communication. The CH583 provides abundant peripheral sources, such as 2Mbps BLE communication module, 2 full-speed USB host and device controller and transceiver, 2 SPIs, 4 UARTs, ADC, touch-key detection module and RTC, etc.

## System Block Diagram

<img src="https://github.com/openwch/ch583/blob/main/image/frame.jpg" alt="frame" style="zoom:50%;" />

### Features

- 32-bit RISC processor, WCH RISC-V4A

- RV32IMAC instruction sets, hardware multiplication and division

- 32KB SRAM, 1MB Flash. ICP, ISP and IAP. OTA wireless upgrade

- B uilt-in 2.4GHz RF transceiver and band and link control. BLE5.3

- 2Mbps, 1Mbps, 500Kbps and 125Kbps

- -98dBm receiving sensitivity, programmable +7dBm transfer power

- Protocol stack and API

- Built-in temperature sensor

- Built-in RTC, supports two modes, timing and trigger

- TwoUSB2.0 full-speed Host/Devices

- 14-channel touch-key

- 14-channel 12-bit ADC

- 4UARTs, 2SPIs, 12-channel PWM, and 1-channel IIC

- 40GPIO ports, of which 4 ports support 5V signal input

- Minimum power supply of 1.7V

- Built-in AES-128 encryption/decryption unit, unique chip ID

- Package: QFN48

## Pin Mapping

The following table shows the mapping between Arduino pin numbers (D0-D29) and the physical GPIO pins on the CH583 microcontroller:

| Arduino Pin | GPIO Pin Físico | Puerto | Funciones alternativas |
|-------------|-----------------|--------|------------------------|
| D0  (0)     | PA0             | GPIOA  | - |
| D1  (1)     | PA1             | GPIOA  | LED_BUILTIN |
| D2  (2)     | PA2             | GPIOA  | - |
| D3  (3)     | PA3             | GPIOA  | - |
| D4  (4)     | PA4             | GPIOA  | I2C0 SDA, A0 |
| D5  (5)     | PA5             | GPIOA  | I2C0 SCL, A1 |
| D6  (6)     | PA6             | GPIOA  | - |
| D7  (7)     | PA7             | GPIOA  | - |
| D8  (8)     | PA8             | GPIOA  | Serial1 RX |
| D9  (9)     | PA9             | GPIOA  | Serial1 TX |
| D10 (10)    | PA10            | GPIOA  | - |
| D11 (11)    | PA11            | GPIOA  | - |
| D12 (12)    | PA12            | GPIOA  | SPI1 MISO, A2 |
| D13 (13)    | PA13            | GPIOA  | SPI1 SS, A3 |
| D14 (14)    | PA14            | GPIOA  | SPI1 SCK, A4 |
| D15 (15)    | PA15            | GPIOA  | SPI1 MOSI, A5 |
| D16 (16)    | PB0              | GPIOB  | SPI0 MISO |
| D17 (17)    | PB1              | GPIOB  | SPI0 SS |
| D18 (18)    | PB2              | GPIOB  | SPI0 SCK |
| D19 (19)    | PB3              | GPIOB  | SPI0 MOSI |
| D20 (20)    | PB4              | GPIOB  | - |
| D21 (21)    | PB5              | GPIOB  | - |
| D22 (22)    | PB6              | GPIOB  | - |
| D23 (23)    | PB7              | GPIOB  | - |
| D24 (24)    | PB8              | GPIOB  | - |
| D25 (25)    | PB9              | GPIOB  | - |
| D26 (26)    | PB10             | GPIOB  | I2C1 SDA, A0 |
| D27 (27)    | PB11             | GPIOB  | I2C1 SCL, A1 |
| D28 (28)    | PB12             | GPIOB  | A2 |
| D29 (29)    | PB13             | GPIOB  | A3 |

**Mapping rules:**
- Pins D0-D15 map to GPIOA (PA0-PA15)
- Pins D16-D29 map to GPIOB (PB0-PB13)

**Notes:**
- `LED_BUILTIN` is mapped to D1 (PA1)
- Serial1 uses D8 (RX) and D9 (TX)
- SPI0 uses D16 (MISO), D17 (SS), D18 (SCK), and D19 (MOSI)
- SPI1 uses D12 (MISO), D13 (SS), D14 (SCK), and D15 (MOSI)
- I2C0 uses D4 (SDA) and D5 (SCL)
- I2C1 uses D26 (SDA) and D27 (SCL)

##  Wiki and Getting Started
[**Getting Started in our Wiki**](https://github.com/ElectronicCats/arduino-wch58x/wiki)

## Backers

Support us with a monthly donation and help us continue our activities. [[Become a backer](https://github.com/sponsors/ElectronicCats)]


## Sponsors

Become a sponsor and get your logo on our README on Github with a link to your site. [[Become a sponsor](https://github.com/sponsors/ElectronicCats)]


# Contributing

We :heart: contributions from everyone. If you want to contribute or have bugfixes, open an issue/PR here.

# Licensing and Credits
* The [Arduino IDE and ArduinoCore-API](https://arduino.cc) are developed and maintained by the Arduino team. The IDE is licensed under GPL.
* [SDK CH58x](https://github.com/ElectronicCats/RISC-V-CH583-CORE) based in [SDK OpenWCH](https://github.com/openwch/ch583)
* [CH552tool python](https://github.com/MarsTechHAN/ch552tool)
* [The xPack GNU RISC-V Embedded GCC](https://github.com/xpack-dev-tools/riscv-none-embed-gcc-xpack/releases)

This core has been developed by Electronic Cats.

```
  Copyright (c) 2015 Electronic Cats SAPI de CV.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
```
