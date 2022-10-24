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
        void ButtonDisable();
        void ButtonEnable();
        String name;
        //flag for registering players at the start of the game;
        bool active = false;

    protected:
        Led *led = nullptr;
        int ledBlinkTimeMS = 250;
        MomentaryButton *button = nullptr;
        
        //not using the first 2 as can't bebug over USB
        const int pinOffset = 2;
        bool enabled = false;
        bool buttonEnabled = true;
};