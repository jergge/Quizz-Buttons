#include "Quizzmaster.h"

Quizzmaster::Quizzmaster(uint8_t y, uint8_t n)
{
    Serial.println("Creating the Quizzmaster");
    //Serial.println(" ");
    buttonYes = new MomentaryButton(y);
    buttonNo = new MomentaryButton(n);
}

bool Quizzmaster::No()
{
    return buttonNo->Pressed();
}

bool Quizzmaster::Yes()
{
    return buttonYes->Pressed();
}