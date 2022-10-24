#include "Quizzmaster.h"

Quizzmaster::Quizzmaster(uint8_t y, uint8_t n)
{
    // Serial.println("Creating the Quizzmaster");
    //Serial.println(" ");
    buttonYes = new MomentaryButton(y, true);
    buttonNo = new MomentaryButton(n, true);
}

bool Quizzmaster::No()
{
    return buttonNo->pressed;
}

bool Quizzmaster::Yes()
{
    return buttonYes->pressed;
}