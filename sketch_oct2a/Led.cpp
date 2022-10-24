#include "Led.h"

Led::Led(int p)  : IODevice(p)
{
    pinMode(pin, OUTPUT);
    // Serial.print("Registered an LED on pin ");
    //     Serial.println(p);
    TurnOff();

}

void Led::Update()
{
    // Serial.print("Updating an LED on pin ");
    // Serial.println(pin);
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
            // nextBlinkChange += blinkDelay;
            // Serial.println("Updating and blinking!     ");
            // Serial.println(enabled);
            // Serial.println(blinking);
            // Serial.println(nextBlinkChange);
            // Serial.println(millis());
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

    //Serial.print("Set blinking to true      ");
}

void Led::StopBlink()
{
    blinking = false;
}