#include "TelemetryReader.h"

TelemetryReader::TelemetryReader(SoftwareSerial& xSerial):
    xSerial(xSerial),
    currentFrame(FRAME_LENGTH)
{
}

void TelemetryReader::update() 
{
    if(xSerial.available())
    {
        readByte();

        if(currentFrame.getSize() == FRAME_LENGTH)
        {
            //for(uint8_t i = 0; i < FRAME_LENGTH; ++i)
            //{
            //    Serial.print(currentFrame.peek(i), HEX);
            //    Serial.print(" ");
            //}
            //Serial.println("");
            uint8_t firstByte = currentFrame.dequeue();

            //The following bytes are a valid frame
            if(firstByte == FRAME_EDGE_BYTE && isValidFrame())
            {
                decodeFrame();
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
void TelemetryReader::readByte() 
{
    uint8_t newByte = xSerial.read();

    currentFrame.enqueue(newByte);
}

void TelemetryReader::decodeFrame()
{
    //Read the next byte
    uint8_t headerByte = currentFrame.dequeue();

    bool gotValidMessage = false;
    switch(headerByte)
    {
        case(0xFE):
        {
            Serial.println("Got linkQuality");

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

void TelemetryReader::parseLinkQuality() 
{
    
}

bool TelemetryReader::isValidFrame() 
{
    return currentFrame.peek(0) != FRAME_EDGE_BYTE;
}

