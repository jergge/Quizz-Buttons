#include <Arduino.h>
#include "IODevice.h"

class MomentaryButton: public IODevice
{
private:

public:
    MomentaryButton(int pinNumber);
    void Update() override;
    
};



