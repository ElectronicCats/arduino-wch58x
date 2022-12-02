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

## Backers

Support us with a monthly donation and help us continue our activities. [[Become a backer](https://github.com/sponsors/ElectronicCats)]


## Sponsors

Become a sponsor and get your logo on our README on Github with a link to your site. [[Become a sponsor](https://github.com/sponsors/ElectronicCats)]


# Contributing
If you want to contribute or have bugfixes, open an issue/PR here.

# Licensing and Credits
* The [Arduino IDE and ArduinoCore-API](https://arduino.cc) are developed and maintained by the Arduino team. The IDE is licensed under GPL.
* Based in [SDK OpenWCH](https://github.com/openwch/ch583)
* [CH552tool python](https://github.com/MarsTechHAN/ch552tool)
* [The xPack GNU RISC-V Embedded GCC](https://xpack.github.io/riscv-none-embed-gcc/)

This core has been developed by Electronic Cats in collaboration with .

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
