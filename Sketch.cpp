#include "Sketch.h"

/*
Sketch::Sketch() :
    xSerial(Globals::RX_PIN, Globals::TX_PIN, true), //Initialise inverted serial to talk to the receiver
    telemetryReader(xSerial)
{
}
*/
Sketch::Sketch()
{
}

void Sketch::setup()
{
    pinMode(10, OUTPUT);
    pinMode(0, OUTPUT);
    //Initialise serial communication
    //xSerial.begin(Globals::RX_BAUD_RATE);
    delay(200);
    
    //Start the hardware serial aswell
    Serial.begin(115200);

    dataDrawer.init();


    dataDrawer.setDataAmount(2);
    delay(20);
    dataDrawer.setDisplayData(0, TelemetryData("Battery", TelemetryData::ANALOG1));
    dataDrawer.setDisplayData(1, TelemetryData("Signal", TelemetryData::LINK_QUALITY));
    //dataDrawer.addDisplayData(TelemetryData("Battery", TelemetryData::ANALOG1));
    //dataDrawer.addDisplayData(TelemetryData("Signal", TelemetryData::LINK_QUALITY));

    delay(200);
    dataDrawer.prepareDisplay();

    digitalWrite(0, HIGH);
}

void Sketch::main()
{
    //telemetryReader.update();

    //dataDrawer.setValue(TelemetryData::ANALOG1, telemetryReader.getDataValue(TelemetryData::ANALOG1));
    //dataDrawer.setValue(TelemetryData::LINK_QUALITY, telemetryReader.getDataValue(TelemetryData::LINK_QUALITY));
    dataDrawer.setValue(TelemetryData::LINK_QUALITY, rand() % 100);

    //Serial.println(telemetryReader.getDataValue(TelemetryData::LINK_QUALITY));

    //Serial.print("Analog 1 : ");
    //Serial.print(telemetryReader.getDataValue(TelemetryData::ANALOG1));
    //Serial.print(" Analog 2 : ");
    //Serial.print(telemetryReader.getDataValue(TelemetryData::ANALOG2));
    //Serial.print(" Link quality : ");
    //Serial.println(telemetryReader.getDataValue(TelemetryData::LINK_QUALITY));
    
    frames++;
    
    drawData();
    //Serial.print("Loop: ");
    Serial.println(frames);
    delay(10);
}

void Sketch::drawData()
{
    dataDrawer.drawNextValue();
}
