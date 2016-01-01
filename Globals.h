#ifndef H_GLOBALS
#define H_GLOBALS

#include <stdint.h>

#include <Arduino.h>

struct Globals
{
    static const uint8_t RX_PIN = 9;
    static const uint8_t TX_PIN = 10;

    static const int RX_BAUD_RATE = 9600;

    static const uint8_t TFT_CS = A4;
    static const uint8_t TFT_RST = A3;
    static const uint8_t TFT_DC = A5;
};

#endif
