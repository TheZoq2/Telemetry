#ifndef H_TELEMETRY_READER
#define H_TELEMETRY_READER

#include <Arduino.h>
#include <SoftwareSerial.h>

#include <stdint.h>

#include "BoundedQueue.h"

/*
 *  Note that the documentation might be wrong. It appears like the bytes sent from my
 *  updated d8r-II plus are only 10 bytes long as opposed to the 11 bytes in the documentation.
 *  
 *  See section 4.1 Frame format in the Two-way system protocol where a change from 10 to 11 bytes
 *  is documented
 */
class TelemetryReader
{
public:
    TelemetryReader(SoftwareSerial& xSerial);
    void update();

    //Read a single byte from the serial feed. 
private:
    void readByte();

    void decodeFrame();

    void parseLinkQuality();

    //Return true if the current frame looks valid
    //This assumes that the startByte has been popped off
    bool isValidFrame();

    static const uint8_t FRAME_LENGTH = 10;

    static const uint8_t FRAME_EDGE_BYTE = 0x7E;

    static const uint8_t LINK_QUALITY_HEADER = 0xFE;

    SoftwareSerial& xSerial;

    
    //The current frame needs to be stored because the tx/rx seem to spit out data as it arrives.
    BoundedQueue<uint8_t> currentFrame;
};
#endif
