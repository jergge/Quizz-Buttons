#include "Led.h"

Led::Led(int p)
{
    pin = p;
    pinMode(pin, OUTPUT);
}

void Led::Update()
{
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

void Led::Blink(int d, bool startOn = true)
{
    blinkDelay = d;
    blinking = true;

    if (startOn)
    {
        TurnOn();
    } else
    {
        TurnOff();    
    }
    
    nextBlinkChange = d + millis();
}

void Led::StopBlink()
{
    blinking = false;
}