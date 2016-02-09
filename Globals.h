#ifndef H_GLOBALS
#define H_GLOBALS

#include <stdint.h>

#include <Arduino.h>

struct Globals
{
    static const uint8_t RX_PIN = 6;
    static const uint8_t TX_PIN = 7;

    static const int RX_BAUD_RATE = 9600;

    static const uint8_t TFT_CS = 10;
    static const uint8_t TFT_RST = 9;
    static const uint8_t TFT_DC = 8;

    static const uint8_t DEBUG_PIN = 23;
};

#endif
