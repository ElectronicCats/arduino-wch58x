/*#include <Arduino.h>
#include "Wire.h"


TwoWire::TwoWire(i2c_inst_t *i2c, pin_size_t sda, pin_size_t scl) {
    _sda = sda;
    _scl = scl;
    _i2c = i2c;
    _clkHz = TWI_CLOCK;
    _begun = false;
    _txBegun = false;
    _buffLen = 0;
}

bool TwoWire::setSDA(pin_size_t pin) {
    if (sdaAllowed(pin)) {
        _sda = pin;
        return true;
    }
    return false;
}

bool TwoWire::setSCL(pin_size_t pin) {
    if (sclAllowed(pin)) {
        _scl = pin;
        return true;
    }
    return false;
}

void TwoWire::setClock(uint32_t hz) {
    _clkHz = hz;
}

// Master mode
void TwoWire::begin() {
    if (_begun) {
        // ERROR
        return;
    }
    _slave = false;
    GPIOB_ModeCfg(GPIO_Pin_13 | GPIO_Pin_12, GPIO_ModeIN_PU);
    
    I2C_Init(I2C_Mode_I2C, _clkHz, I2C_DutyCycle_16_9, I2C_Ack_Enable, I2C_AckAddr_7bit, TxAdderss);
    while(I2C_GetFlagStatus(I2C_FLAG_BUSY) != RESET);

    I2C_GenerateSTART(ENABLE);
    while(!I2C_CheckEvent(I2C_EVENT_MASTER_MODE_SELECT));

    _begun = true;
    _txBegun = false;
    _buffLen = 0;
}

// Slave mode
void TwoWire::begin(uint8_t addr) {
    // Slave moce isn't documented in the SDK, need to twiddle raw registers
    // and use bare interrupts.  TODO to implement, for now.
#if 0
    if (_begun) {
        // ERROR
        return;
    }
    _slave = true;
    GPIOB_ModeCfg(GPIO_Pin_13 | GPIO_Pin_12, GPIO_ModeIN_PU);
    
    I2C_Init(I2C_Mode_I2C, 400000, I2C_DutyCycle_16_9, I2C_Ack_Enable, I2C_AckAddr_7bit, addr);

    while(!I2C_CheckEvent(I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED));


    I2C_GenerateSTART(ENABLE);
#endif
}

void TwoWire::end() {
    if (!_begun) {
        // ERROR
        return;
    }

    _begun = false;
    _txBegun = false;
}

void TwoWire::beginTransmission(uint8_t addr) {
    if (!_begun || _txBegun) {
        // ERROR
        return;
    }
    _addr = addr;
    _buffLen = 0;
    _txBegun = true;
}

bool TwoWire::sdaAllowed(pin_size_t pin) {
    switch (i2c_hw_index(_i2c)) {
        case 0:
            switch (pin) {
                case 0:
                case 4:
                case 16:
                case 20:
                    return true;
            }
            break;
        case 1:
            switch (pin) {
                case 8:
                case 12:
                case 24:
                case 28:
                    return true;
            }
            break;
    }
    return false;
}

bool TwoWire::sclAllowed(pin_size_t pin) {
    switch (i2c_hw_index(_i2c)) {
        case 0:
            switch (pin) {
                case 1:
                case 5:
                case 17:
                case 21:
                    return true;
            }
            break;
        case 1:
            switch (pin) {
                case 9:
                case 13:
                case 25:
                case 29:
                    return true;
            }
            break;
    }
    return false;
}

size_t TwoWire::requestFrom(uint8_t address, size_t quantity, bool stopBit) {
    if (!_begun || _txBegun || !quantity || (quantity > sizeof(_buff))) {
        return 0;
    }

    size_t byteRead = 0;
    _buffLen = i2c_read_blocking(_i2c, address, _buff, quantity, !stopBit);
    return _buffLen;
}

size_t TwoWire::requestFrom(uint8_t address, size_t quantity) {
    return requestFrom(address, quantity, true);
}

// Errors:
//  0 : Success
//  1 : Data too long
//  2 : NACK on transmit of address
//  3 : NACK on transmit of data
//  4 : Other error
uint8_t TwoWire::endTransmission(bool stopBit) {
    if (!_begun || !_txBegun || !_buffLen) {
        return 4; 
    }
    auto len = _buffLen;
    I2C_GenerateSTOP(ENABLE);
    _buffLen = 0;
    _txBegun = false;
    return 0;
}

uint8_t TwoWire::endTransmission() {
  return endTransmission(true);
}

size_t TwoWire::write(uint8_t ucData) {
    if (!_begun || !_txBegun || (_buffLen == sizeof(_buff))) {
        return 0;
    }
    _buff[_buffLen++] = ucData;
    return 1 ;
}

size_t TwoWire::write(const uint8_t *data, size_t quantity) {
    for (size_t i = 0; i < quantity; ++i) {
        if (!write(data[i])) {
            return i;
        }
    }

    return quantity;
}

int TwoWire::available(void) {
    return _begun  ? _buffLen - _buffOff : 0;
}

int TwoWire::read(void) {
    if (available()) {
        return _buff[_buffOff++];
    }
    return -1; // EOF
}

int TwoWire::peek(void) {
    if (available()) {
        return _buff[_buffOff];
    }
    return -1; // EOF
}

void TwoWire::flush(void) {
    // Do nothing, use endTransmission(..) to force
    // data transfer.
}


void TwoWire::onReceive(void(*function)(int))
{
    _onReceiveCallback = function;
}

void TwoWire::onRequest(void(*function)(void))
{
    _onRequestCallback = function;
}

TwoWire Wire(i2c0, 0, 1);
TwoWire Wire1(i2c1, 4, 5);
*/