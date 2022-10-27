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

        //make a sound for a number of miliseconds
        //buzzer is enabled when this functin is called
        void PlayForMS(unsigned long duration);

    private:
        unsigned long nextPulse;
        unsigned long pulseDelayMS = 10;
        unsigned long endTime;
        bool on = false;
};