#include "MomentaryButton.h"

// Buttons are wired between InputPin and GND
// When the InputPin is HIGHT -> the button is not pressed
// Pressing the button shorts to GND and sends LOW to InputPin

MomentaryButton::MomentaryButton(uint8_t p) : IODevice(p)
{
    pinMode(p, INPUT_PULLUP);
    Serial.print("Registered a button on pin ");
        Serial.println(p);
}

void MomentaryButton::Update()
{
    int currentState = digitalRead(pin);

    if (currentState == LOW)
    {   
        // Serial.print("      1     ");
    } else if(currentState == HIGH)
    {
        // Serial.print("      0      ");
    }

    if ( currentState != previousState )
    {
        if (currentState == HIGH)
        {

        } else
        {
            Serial.print("      button pressed down      ");
        }
    }
    previousState = currentState;
}

bool MomentaryButton::Pressed()
{
    if (digitalRead(pin) == LOW)
    {
        return true;
    }
    return false;
}
