#pragma once
#include "UpdateableObject.h"
#include "IODevice.h"

class MomentaryButton: public IODevice, public  UpdateableObject
{
    public:
        MomentaryButton(uint8_t pinNumber, bool pullUp = false);
        void Update();
        bool IsPressed();

    private:
        bool wasPressedLast;
        bool pullUp = false; 
        int debouceTimeMS = 100;
};
