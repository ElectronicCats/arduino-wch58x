/*
#ifndef TwoWire_h
#define TwoWire_h

#include "api/HardwareI2C.h"
#include "CH58x_common.h"

 // WIRE_HAS_END means Wire has end()
#define WIRE_HAS_END 1

class TwoWire : public HardwareI2C
{
public:
    TwoWire(i2c_inst_t *i2c, pin_size_t sda, pin_size_t scl);

    // Start as Master
    void begin();
    // Start as Slave
    void begin(uint8_t address);
    // Shut down the I2C interface
    void end();

    bool setSDA(pin_size_t sda);
    bool setSCL(pin_size_t scl);
    void setClock(uint32_t freqHz) override;

    void beginTransmission(uint8_t);
    uint8_t endTransmission(bool stopBit);
    uint8_t endTransmission(void);

    size_t requestFrom(uint8_t address, size_t quantity, bool stopBit);
    size_t requestFrom(uint8_t address, size_t quantity);

    size_t write(uint8_t data);
    size_t write(const uint8_t * data, size_t quantity);

    virtual int available(void);
    virtual int read(void);
    virtual int peek(void);
    virtual void flush(void);
    void onReceive(void(*)(int));
    void onRequest(void(*)(void));

    inline size_t write(unsigned long n) { return write((uint8_t)n); }
    inline size_t write(long n) { return write((uint8_t)n); }
    inline size_t write(unsigned int n) { return write((uint8_t)n); }
    inline size_t write(int n) { return write((uint8_t)n); }
    using Print::write;

private:
    // Verifies the passed in pin can be used by this I2C device
    bool sdaAllowed(pin_size_t pin);
    bool sclAllowed(pin_size_t pin);

    i2c_inst_t *_i2c;
    pin_size_t _sda;
    pin_size_t _scl;
    int _clkHz;

    bool _begun;
    bool _slave;
    uint8_t _addr;
    bool _txBegun;

    uint8_t _buff[256];
    int _buffLen;
    int _buffOff;

    // Callback user functions
    void (*_onRequestCallback)(void);
    void (*_onReceiveCallback)(int);

    // TWI clock frequency
    static const uint32_t TWI_CLOCK = 100000;
};

extern TwoWire Wire;
extern TwoWire Wire1;

#endif
*/