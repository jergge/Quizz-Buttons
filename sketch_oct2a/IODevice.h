#pragma once
#include <Arduino.h>

class IODevice
{
protected:
    uint8_t pin;
    bool enabled = true;
public:
    virtual void Update();
    IODevice(uint8_t pinNumber);
    IODevice() {};
    void Enable();
    void Disable();
};

