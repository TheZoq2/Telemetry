#ifndef H_SKETCH
#define H_SKETCH

//Arduino stuff
#include <Arduino.h>
#include <SoftwareSerial.h>

#include <stdint.h>


#include "Globals.h"
#include "TelemetryReader.h"

class Sketch
{
public:
    Sketch();

    void setup();
    void main();
private:
    SoftwareSerial xSerial;

    TelemetryReader telemetryReader;
};
#endif
