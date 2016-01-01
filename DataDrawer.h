#ifndef H_DATA_DRAWER
#define H_DATA_DRAWER

#include <stdlib.h>

//Display stuff
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#include "Globals.h"
#include "TelemetryData.h"

class DataDrawer
{
public:
    DataDrawer();
    ~DataDrawer();

    void init();

    //setDisplayedDataArray and init must be called before this
    //Draw static data to the display. This is slow and should only
    //be done once to set up the display
    void prepareDisplay();

    void setValue(TelemetryData::DataIndex index, TelemetryData::ValueType value);
    void drawNextValue();

    void setDataAmount(uint8_t dispDataLen);
    void setDisplayData(uint8_t index, TelemetryData newData);
private:
    static const uint8_t nameLength = 32;

    static const uint16_t BACKGROUND_COLOR = ST7735_BLACK;
    static const uint16_t TEXT_COLOR = ST7735_WHITE;

    static const uint8_t TEXT_SIZE = 1;
    static const uint8_t DATA_SIZE = 2;
    static const uint8_t TEXT_HEIGHT = 30;
    static const uint8_t DATA_TEXT_Y_OFFSET = 10;

    static const uint16_t DATA_START = 24;

    void drawTextLine(const char* line);

    Adafruit_ST7735 tft = Adafruit_ST7735(Globals::TFT_CS, Globals::TFT_DC, Globals::TFT_RST);

    uint16_t currentHeight;

    //Array of data to be displayed by the drawer.
    TelemetryData* displayedData = NULL;
    uint8_t dispDataLen;
    uint8_t currentDrawnIndex;
};
#endif
