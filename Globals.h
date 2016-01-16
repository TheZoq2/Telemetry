#ifndef H_GLOBALS
#define H_GLOBALS

#include <stdint.h>

#include <Arduino.h>

struct Globals
{
    static const uint8_t RX_PIN = 6;
    static const uint8_t TX_PIN = 7;

    static const int RX_BAUD_RATE = 9600;

    static const uint8_t TFT_CS = 16;
    static const uint8_t TFT_RST = 17;
    static const uint8_t TFT_DC = 15;
};

#endif
