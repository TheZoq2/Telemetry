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
    delay(200);
    
    //Start the hardware serial aswell
    Serial.begin(115200);

    Serial.println("Initialising monitor");

    dataDrawer.init();


    dataDrawer.setDataAmount(2);
    dataDrawer.setDisplayData(0, TelemetryData("Battery", TelemetryData::ANALOG1));
    dataDrawer.setDisplayData(1, TelemetryData("Signal", TelemetryData::LINK_QUALITY));
    //dataDrawer.addDisplayData(TelemetryData("Battery", TelemetryData::ANALOG1));
    //dataDrawer.addDisplayData(TelemetryData("Signal", TelemetryData::LINK_QUALITY));

    delay(200);
    dataDrawer.prepareDisplay();
    Serial.println("Setup complete");

    //xSerial.available();
    Serial.println("Starting main");

    //xSerial.available();
}

void Sketch::main()
{
    telemetryReader.update();

    dataDrawer.setValue(TelemetryData::ANALOG1, telemetryReader.getDataValue(TelemetryData::ANALOG1));
    dataDrawer.setValue(TelemetryData::LINK_QUALITY, telemetryReader.getDataValue(TelemetryData::LINK_QUALITY));

    Serial.println(telemetryReader.getDataValue(TelemetryData::LINK_QUALITY));

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
    dataDrawer.drawNextValue();
}
