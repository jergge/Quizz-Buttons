#pragma once
#include "IODevice.h"
#include "includes.h"
#include "Jergge.h"

class Led: public IODevice
{
    public:
        Led(int pinNumber);
        void Update() override;
        void On();
        void Off();
        void Blink(int delayMS, bool startOn = true);
        void StopBlink();

    protected:
        void TurnOn();
        void TurnOff();
        void Flip();
        bool output;
        bool blinking = false;
        int blinkDelay;
        unsigned long nextBlinkChange;
};