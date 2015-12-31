#include "Sketch.h"

Sketch::Sketch() :
    xSerial(Globals::RX_PIN, Globals::TX_PIN, true), //Initialise inverted serial to talk to the receiver
    telemetryReader(xSerial)
{
}

void Sketch::setup()
{
    //Set up pins for serial
    pinMode(Globals::RX_PIN, INPUT);
    pinMode(Globals::TX_PIN, OUTPUT);
    //Initialise serial communication
    xSerial.begin(Globals::RX_BAUD_RATE);
    
    //Start the hardware serial aswell
    Serial.begin(115200);

    Serial.println("Setup complete");

    dataDrawer.init();
    dataDrawer.prepareDisplay();
}

void Sketch::main()
{
    telemetryReader.update();

    //Serial.print("Analog 1 : ");
    //Serial.print(telemetryReader.getDataValue(TelemetryData::ANALOG1));
    //Serial.print(" Analog 2 : ");
    //Serial.print(telemetryReader.getDataValue(TelemetryData::ANALOG2));
    //Serial.print(" Link quality : ");
    //Serial.println(telemetryReader.getDataValue(TelemetryData::LINK_QUALITY));
    
    frames++;
    
    drawData();
    Serial.print("Loop: ");
    Serial.println(frames);
}

void Sketch::drawData()
{
}
