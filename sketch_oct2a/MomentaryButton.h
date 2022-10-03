#pragma once
#include "includes.h"

class MomentaryButton: public IODevice
{
private:
    void OnPressed();

public:
    MomentaryButton(int pinNumber);
    void Update() override;
    
};



