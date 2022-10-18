#pragma once
//#include "includes.h"
#include "Led.h"
#include "Jergge.h"

class MomentaryButton: public IODevice
{
public:
    MomentaryButton(uint8_t pinNumber);
    void Update();
    bool Pressed();
private:
    int previousState;
    
};



