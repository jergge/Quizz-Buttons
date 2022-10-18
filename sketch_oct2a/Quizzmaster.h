#pragma once
#include "Led.h"
#include "MomentaryButton.h"

class Quizzmaster
{
    public:
        Quizzmaster(int APortYes, int APortNo);
        bool Yes();
        bool No();

    protected:
        MomentaryButton *buttonYes;
        MomentaryButton *buttonNo;
};