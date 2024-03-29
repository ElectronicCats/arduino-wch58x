#pragma once

// Pin definitions taken from:

// LEDs
#define PIN_LED        (1u)
#define LED_BUILTIN PIN_LED

// Serial
#define PIN_SERIAL1_TX (9u)
#define PIN_SERIAL1_RX (8u)

// SPI
#define PIN_SPI0_MISO  (16u)
#define PIN_SPI0_MOSI  (19u)
#define PIN_SPI0_SCK   (18u)
#define PIN_SPI0_SS    (17u)

#define PIN_SPI1_MISO  (12u)
#define PIN_SPI1_MOSI  (15u)
#define PIN_SPI1_SCK   (14u)
#define PIN_SPI1_SS    (13u)

// Wire
#define PIN_WIRE0_SDA  (4u)
#define PIN_WIRE0_SCL  (5u)

#define PIN_WIRE1_SDA  (26u)
#define PIN_WIRE1_SCL  (27u)

#define SERIAL_HOWMANY (1u)
#define SPI_HOWMANY    (1u)
#define WIRE_HOWMANY   (1u)

static const uint8_t A0 = (4u);
static const uint8_t A1 = (5u);
static const uint8_t A2 = (12u);
static const uint8_t A3 = (13u);
static const uint8_t A4 = (14u);
static const uint8_t A5 = (15u);
