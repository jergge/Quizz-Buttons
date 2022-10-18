#include "Quizzmaster.h"

Quizzmaster::Quizzmaster(int y, int n)
{
    buttonNo = new MomentaryButton(n);
    buttonYes = new MomentaryButton(y);
}

bool Quizzmaster::No()
{
    return buttonNo->Pressed();
}

bool Quizzmaster::Yes()
{
    return buttonYes->Pressed();
}