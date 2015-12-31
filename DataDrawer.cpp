#include "DataDrawer.h"

DataDrawer::DataDrawer() : 
    tft(Globals::TFT_CS, Globals::TFT_DC, Globals::TFT_RST),
    inputData(inputData)
{

}
void DataDrawer::init() 
{
    //Initialising the TFT screen
    tft.initR(INITR_BLACKTAB);
    tft.fillScreen(BACKGROUND_COLOR);
}

void DataDrawer::prepareDisplay()
{
    currentHeight = 0;
    tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
    tft.setTextSize(TEXT_SIZE);

    drawTextLine("Battery");
    drawTextLine("Signal");

    currentHeight = 0;
}

void DataDrawer::drawTextLine(const char* line)
{
    tft.setCursor(0, currentHeight);
    tft.print(line);
    currentHeight += TEXT_HEIGHT;
}

void DataDrawer::drawValue()
{
    tft.setCursor(
}
