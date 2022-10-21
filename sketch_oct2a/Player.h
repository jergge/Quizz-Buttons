#pragma once
#include "includes.h"
#include "Led.h"
#include "MomentaryButton.h"

//holdes everything tied to a player including
//the buzzer (button)
//info light for the quizzmaster
//a function to lock them out for a round
//... and a function to reenable them

class Player
{
    public:
        Player();
        Player(int playerID);
        int id;
        bool ButtonPushed();
        bool IsEnabled();
        void Enable();
        void Disable();
        void LedEnable();
        void LedDisable();

    protected:
        Led *led = nullptr;
        MomentaryButton *button = nullptr;
        
        //not using the first 2 as i can't bebug over USB
        const int pinOffset = 2;
        bool enabled = false;
};