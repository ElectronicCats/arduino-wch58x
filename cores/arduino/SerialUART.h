#ifdef __cplusplus

#ifndef __SERIALUART_H__
#define __SERIALUART_H__

#include <Arduino.h>
#include "api/HardwareSerial.h"
#include "CH58x_common.h"

class SerialUART : public Stream
{
public:
    SerialUART(pin_size_t tx, pin_size_t rx) {_tx = tx; _rx = rx; }
    
    bool setPinout(pin_size_t tx, pin_size_t rx);

    void begin(unsigned long baud = 115200) { begin(baud, SERIAL_8N1); };
    void begin(unsigned long baud, uint16_t config);
    void end();

    virtual int peek();
    virtual int read();
    virtual int available();
    virtual int availableForWrite();
    virtual void flush();
    virtual size_t write(uint8_t c);
    virtual size_t write(const uint8_t *p, size_t len);
    using Print::write;
    operator bool();
private:
    bool _running = false;
    pin_size_t _tx, _rx;
    int _baud;
    int _peek;
};

extern SerialUART Serial1; // HW UART 0
extern SerialUART Serial2; // HW UART 1

#endif
#endif