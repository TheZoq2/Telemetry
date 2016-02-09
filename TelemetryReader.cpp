#include "TelemetryReader.h"

TelemetryReader::TelemetryReader():
    currentFrame(FRAME_LENGTH)
{
    TELEM_SERIAL.begin(9600, SERIAL_8N2_RXINV_TXINV);
}

void TelemetryReader::update() 
{
    if(TELEM_SERIAL.available())
    {
        Serial.println("Got serial");
        readByte();

        if(currentFrame.getSize() == FRAME_LENGTH)
        {
            uint8_t firstByte = currentFrame.dequeue();

            //The following bytes are a valid frame
            if(firstByte == FRAME_EDGE_BYTE && isValidFrame())
            {
                decodeFrame();
            }
        }
    }
}

uint8_t TelemetryReader::getDataValue(TelemetryData::DataIndex dataType) 
{
    return dataValues[dataType];
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void TelemetryReader::readByte() 
{
    uint8_t newByte = TELEM_SERIAL.read();

    currentFrame.enqueue(newByte);
}

void TelemetryReader::decodeFrame()
{
    //Read the next byte
    uint8_t headerByte = currentFrame.dequeue();

    Serial.println("Read header byte");

    bool gotValidMessage = false;
    switch(headerByte)
    {
        case(RC_STATUS_HEADER):
        {
            parseRCStatus();

            gotValidMessage = true;
            break;
        }
        default:
            Serial.print("Unknown header: ");
            Serial.println(headerByte, HEX);
            break;
    }

    //We are done reading this frame, remove the rest of it
    if(gotValidMessage)
    {
        currentFrame.clear();
    }

}

//The RC status frame has the following structure
//0xXX Analog port1
//0xXX Analog port2
//0xXX Link quality
void TelemetryReader::parseRCStatus() 
{
    dataValues[TelemetryData::ANALOG1] = currentFrame.dequeue();
    dataValues[TelemetryData::ANALOG2] = currentFrame.dequeue();
    dataValues[TelemetryData::LINK_QUALITY] = currentFrame.dequeue();
}

bool TelemetryReader::isValidFrame() 
{
    return currentFrame.peek(0) != FRAME_EDGE_BYTE;
}

