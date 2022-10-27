#include "MomentaryButton.h"

MomentaryButton::MomentaryButton(uint8_t p, bool pull) : IODevice(p)
{
    if(pull)
    {
        pinMode(p, INPUT_PULLUP);
    } else {
        pinMode(p, INPUT);
    }
    
    pullUp = pull;
    Serial.print(F("Registered a button on pin "));
        Serial.println(p);
}

void MomentaryButton::Update()
{
    // Serial.println(F("Updating a button "));
    if ( IsPressed() != wasPressedLast )
    {
        if ( IsPressed() )
        {
        //    Serial.println(F("button pressed down      "));
            pressed = true;
        } else
        {
            // Serial.println(F("      button released      "));
            pressed = false;
        }
    }
    wasPressedLast = IsPressed();
}

bool MomentaryButton::IsPressed()
{
    if (
        ( digitalRead(pin) == LOW  &&  pullUp ) ||
        ( digitalRead(pin) == HIGH && !pullUp )
        )
    {
        return true;
    }
    return false;
}
