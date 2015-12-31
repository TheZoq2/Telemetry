#ifndef H_DATA_DRAWER
#define H_DATA_DRAWER

//Display stuff
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#include "Globals.h"
class DataDrawer
{
public:
    DataDrawer();

    void init();

    //Draw static data to the display. This is slow and should only
    //be done once to set up the display
    void prepareDisplay();

private:
    static const uint8_t nameLength = 32;

    static const uint16_t BACKGROUND_COLOR = ST7735_BLACK;
    static const uint16_t TEXT_COLOR = ST7735_WHITE;

    static const uint8_t TEXT_SIZE = 1;
    static const uint8_t TEXT_HEIGHT = 30;

    static const uint16_t DATA_START = 64;

    void drawTextLine(const char* line);

    Adafruit_ST7735 tft = Adafruit_ST7735(Globals::TFT_CS, Globals::TFT_DC, Globals::TFT_RST);

    uint16_t currentHeight;
};
#endif
