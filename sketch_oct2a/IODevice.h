#include <Arduino.h>

class IODevice
{
protected:
    int pin;
    bool enabled;
public:
    virtual void Update();
    void Enable();
    void Disable();
};

