#include "MomentaryButton.h"

// Buttons are wired between InputPin and GND
// When the InputPin is HIGHT -> the button is not pressed
// Pressing the button shorts to GND and sends LOW to InputPin

MomentaryButton::MomentaryButton(uint8_t p, bool pull) : IODevice(p)
{
    if(pull)
    {
        pinMode(p, INPUT_PULLUP);
    } else {
        pinMode(p, INPUT);
    }
    pullUp = pull;
    // Serial.print("Registered a button on pin ");
    //     Serial.println(p);
}

void MomentaryButton::Update()
{
    int currentState = Pressed();

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
    if (
        ( digitalRead(pin) == LOW  &&  pullUp )
        ||
        ( digitalRead(pin) == HIGH && !pullUp )
        )
    {
        return true;
    }
    return false;
}
