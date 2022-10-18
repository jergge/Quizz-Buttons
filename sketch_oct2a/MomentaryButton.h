#pragma once
//#include "includes.h"
#include "Led.h"
#include "Jergge.h"

class MomentaryButton: public IODevice
{
public:
    MomentaryButton(int pinNumber);
    void Update();
    bool Pressed();
private:
    int previousState;
    
};



