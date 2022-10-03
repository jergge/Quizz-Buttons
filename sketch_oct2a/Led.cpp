#include "Led.h"

Led::Led(int p)
{
    pin = p;
    pinMode(pin, OUTPUT);
}

void Led::Update()
{
    if (!enabled)
    {
        TurnOff();
        StopBlink();
        return;
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
}

void Led::StopBlink()
{
    blinking = false;
}

void Led::Enable()
{
    enabled = true;
}

void Led::Disable()
{
    enabled = false;
}