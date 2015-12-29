#ifndef H_TELEMETRY_READER
#define H_TELEMETRY_READER

#include <Arduino.h>
#include <SoftwareSerial.h>

#include <stdint.h>

#include "BoundedQueue.h"

class TelemetryReader
{
public:
    TelemetryReader(SoftwareSerial& xSerial);
    void update();

    //Read a single byte from the serial feed. 
    void readByte();

    void decodeFrame();

    void parseLinkQuality();
private:
    static const uint8_t FRAME_LENGTH = 11;

    static const uint8_t FRAME_EDGE_BYTE = 0x7E;

    static const uint8_t LINK_QUALITY_HEADER = 0xFE;

    SoftwareSerial& xSerial;

    
    //The current frame needs to be stored because the tx/rx seem to spit out data as it arrives.
    BoundedQueue<uint8_t> currentFrame;
};
#endif
