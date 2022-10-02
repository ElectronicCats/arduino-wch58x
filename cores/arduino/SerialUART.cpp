#include "SerialUART.h"

bool SerialUART::setPinout(pin_size_t tx, pin_size_t rx)
{
    _tx = tx;
    _rx = rx;
    GPIOA_SetBits(_tx << 1);
    GPIOA_ModeCfg(_rx << 1, GPIO_ModeIN_PU);
    GPIOA_ModeCfg(_tx << 1, GPIO_ModeOut_PP_5mA);

    return true;
}

void SerialUART::begin(unsigned long baud, uint16_t config)
{
    GPIOA_SetBits(GPIO_Pin_9);
    GPIOA_ModeCfg(GPIO_Pin_8, GPIO_ModeIN_PU);      // RXD
    GPIOA_ModeCfg(GPIO_Pin_9, GPIO_ModeOut_PP_5mA); // TXD

    _baud = baud;
    
    UART1_BaudRateCfg(_baud);
    R8_UART1_FCR = (2 << 6) | RB_FCR_TX_FIFO_CLR | RB_FCR_RX_FIFO_CLR | RB_FCR_FIFO_EN; // FIFO�򿪣�������4�ֽ�
    R8_UART1_LCR = RB_LCR_WORD_SZ;
    R8_UART1_IER = RB_IER_TXD_EN;
    R8_UART1_DIV = 1;

    _running = true;
}

void SerialUART::end()
{
    _running = false;
}

int SerialUART::peek()
{
    return _peek;
}

int SerialUART::read()
{
    return UART1_RecvByte();
}

int SerialUART::available()
{
    return -1;
}

int SerialUART::availableForWrite()
{
    return -1;
}

void SerialUART::flush()
{
    
}

size_t SerialUART::write(uint8_t c)
{
    if (!_running)
    {
        return 0;
    }
    UART1_SendByte(c);
    return 1;
}

size_t SerialUART::write(const uint8_t *p, size_t len)
{
    if (!_running)
    {
        return 0;
    }
    size_t cnt = len;
    while (cnt)
    {
        if(R8_UART1_TFC != UART_FIFO_SIZE)
        {
          R8_UART1_THR = *p;
          cnt--;
          p++;
        }
    }
    return len;
}

SerialUART::operator bool()
{
    return _running;
}

SerialUART Serial1(9, 8);
SerialUART Serial2(4, 5);