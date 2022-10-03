#pragma once
#include <Arduino.h>

class IODevice
{
protected:
    int pin;
    bool enabled = true;
public:
    virtual void Update();
    IODevice(int pinNumber);
    IODevice() {};
    void Enable();
    void Disable();
};

