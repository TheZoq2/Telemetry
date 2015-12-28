#include "Sketch.h"

Sketch::Sketch() :
    serial(Globals::RX_PIN, Globals::TX_PIN, true) //Initialise inverted serial to talk to the receiver
{
}

void Sketch::setup()
{
    //Set up pins for serial
    pinMode(Globals::RX_PIN, INPUT);
    pinMode(Globals::TX_PIN, OUTPUT);
    //Initialise serial communication
    serial.begin(Globals::RX_BAUD_RATE);
    
    //Start the hardware serial aswell
    Serial.begin(115200);

    Serial.println("Setup complete");
}
void Sketch::main()
{
    while(serial.available())
    {
        Serial.println(serial.available());
        serial.read();
    }

}
