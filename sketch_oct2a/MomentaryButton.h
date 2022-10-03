#pragma once
#include "includes.h"

class MomentaryButton: public IODevice
{
private:
    void OnPressed();
    int maxRegistered = 6;
    Led** registeredOnPressed = new Led*[maxRegistered];
    int registeredIndex = 0;


public:
    MomentaryButton(int pinNumber);
    void RegisterOnPressed(Led * ledPointer);
    void Update() override;
    
};



