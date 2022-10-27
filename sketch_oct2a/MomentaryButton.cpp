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
    int currentState = IsPressed();

    if ( IsPressed() )
    {   
        // Serial.print("      1     ");
    } else if( !IsPressed() )
    {
        // Serial.print("      0      ");
    }

    if ( IsPressed() != wasPressedLast )
    {
        if ( IsPressed() )
        {
           // Serial.println("button pressed down      ");
            pressed = true;
        } else
        {
            //Serial.println("      button released      ");
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
