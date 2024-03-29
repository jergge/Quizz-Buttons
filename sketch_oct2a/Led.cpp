#include "Led.h"

Led::Led(uint8_t p)  : IODevice(p)
{
    pinMode(pin, OUTPUT);
    Serial.print(F("Registered an LED on pin "));
        Serial.println(p);
    TurnOff();

}

void Led::Update()
{
    if (!enabled)
    {
        TurnOff();
        StopBlink();
        return;
        //Serial.println("Turning off an led... v");
    }
    if(blinking)
    {
        if (nextBlinkChange <= millis())
        {
            Flip();
            nextBlinkChange += blinkDelay;
        }
    }
}

void Led::TurnOn()
{
    digitalWrite(pin, HIGH);
    output = true;
}

void Led::TurnOff()
{
    digitalWrite(pin, LOW);
    output = false;
}

void Led::Flip()
{
    // Serial.println(F("Flipping LED"));
    if(output)
    {
        TurnOff();
    } else 
    {
        TurnOn();
    }
}

void Led::On()
{
    TurnOn();
}

void Led::Off()
{
    TurnOff();
}

void Led::Blink(int d, bool startOn)
{
    blinkDelay = d;

    enabled = true;

    if (!blinking)
    {
        if (startOn)
        {
            TurnOn();
        } else
        {
            TurnOff();    
        }
    }
    
    nextBlinkChange = d + millis();
    blinking = true;

    // Serial.print("Set blinking to true      ");
    // Serial.println(d);
}

void Led::StopBlink()
{
    blinking = false;
}