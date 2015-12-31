#include <SoftwareSerial.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>

#include "Sketch.h"

Sketch sketch;
void setup()
{
    sketch.setup();
}

void loop()
{
    sketch.main();
}
