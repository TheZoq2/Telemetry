#include <SoftwareSerial.h>

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
