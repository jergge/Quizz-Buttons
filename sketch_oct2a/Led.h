#pragma once
#include "IODevice.h"
#include "UpdateableObject.h"

class Led: public IODevice, public UpdateableObject
{
    public:
        Led(uint8_t pinNumber);
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