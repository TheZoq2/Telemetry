#ifndef H_SKETCH
#define H_SKETCH

//Arduino stuff
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <AltSoftSerial.h>

//Display stuff
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#include <stdint.h>


#include "Globals.h"
#include "TelemetryReader.h"
#include "TelemetryData.h"
#include "DataDrawer.h"

class Sketch
{
public:
    Sketch();

    void setup();
    void main();

    void drawData();
private:
    SoftwareSerial xSerial;

    TelemetryReader telemetryReader;

    DataDrawer dataDrawer;
    int frames = 0;
};
#endif
