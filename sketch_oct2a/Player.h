#pragma once
#include "Led.h"
#include "MomentaryButton.h"

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
        void Blink();
        void LedOn();
        void LedOff();
        //void LedBlink();

    protected:
        Led *led = nullptr;
        int ledBlinkTimeMS = 500;
        MomentaryButton *button = nullptr;
        
        //not using the first 2 as i can't bebug over USB
        const int pinOffset = 2;
        bool enabled = false;
};