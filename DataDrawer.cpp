#include "DataDrawer.h"

DataDrawer::DataDrawer() : 
    tft(Globals::TFT_CS, Globals::TFT_DC, Globals::TFT_RST)
{
    currentHeight = 0;

    displayedData = NULL;
    dispDataLen = 0;
}
DataDrawer::~DataDrawer()
{
    if(displayedData != NULL)
    {
        delete[] displayedData;

        displayedData = NULL;
    }
}

void DataDrawer::init() 
{
    //Initialising the TFT screen
    tft.initR();
    tft.fillScreen(BACKGROUND_COLOR);
}

void DataDrawer::setDataAmount(uint8_t dispDataLen)
{
    if(displayedData != NULL)
    {
        delete[] displayedData;
    }
    this->dispDataLen = dispDataLen;

    this->displayedData = new TelemetryData[dispDataLen];
    
}
void DataDrawer::setDisplayData(uint8_t index, TelemetryData newData)
{
    digitalWrite(0, HIGH);
    displayedData[index] = newData;
}

void DataDrawer::prepareDisplay()
{
    currentHeight = 0;
    tft.setTextColor(TEXT_COLOR, BACKGROUND_COLOR);
    //tft.setBgColor(BACKGROUND_COLOR);
    tft.setTextSize(TEXT_SIZE);

    tft.fillRect(0,0,100,100, ST7735_RED);
    //drawTextLine("Hello world");
    //Draw the description text for all the data
    for(int i = 0; i < dispDataLen; ++i)
    {

        drawTextLine(displayedData[i].getName());
        //drawTextLine("Hello world");
    }
}

void DataDrawer::drawTextLine(const char* line)
{
    tft.setCursor(0, currentHeight);
    tft.print(line);
    currentHeight += TEXT_HEIGHT;
}

void DataDrawer::setValue(TelemetryData::DataIndex index, TelemetryData::ValueType value)
{
    for(int i = 0; i < dispDataLen; ++i)
    {
        if(displayedData[i].getDataIndex() == index)
        {
            displayedData[i].setValue(value);
        }
    }
}
void DataDrawer::drawNextValue()
{
    //Calculate the offset
    uint16_t drawY = currentDrawnIndex * TEXT_HEIGHT + DATA_TEXT_Y_OFFSET;

    tft.setCursor(DATA_START, drawY);
    tft.setTextSize(DATA_SIZE);
    
    //Draw the actual data
    tft.print(displayedData[currentDrawnIndex].getValue());
    //tft.print("ABCDEFGHIJ");
    //tft.fillRect(0,0,100,100, ST7735_WHITE);
    


    currentDrawnIndex = (currentDrawnIndex + 1) % dispDataLen;
}
