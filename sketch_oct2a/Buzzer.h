#pragma once
#include "UpdateableObject.h"
#include "IODevice.h"

class Buzzer : public UpdateableObject, IODevice
{
    public:
        Buzzer(uint8_t pinNumber);
        void Update() override;
        void On();
        void Off();
        void Flip();

    private:
        int nextPulse;
        int pulseDelayMS = 10;
        bool on = false;
};