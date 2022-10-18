#pragma once
#include "Led.h"
#include "MomentaryButton.h"

class Quizzmaster
{
    public:
        Quizzmaster(uint8_t APortYes, uint8_t APortNo);
        bool Yes();
        bool No();

    protected:
        MomentaryButton *buttonYes;
        MomentaryButton *buttonNo;
};