#include "IODevice.h"

void IODevice::Enable()
{
    enabled = true;
}

void IODevice::Disable()
{
    enabled = false;
}

IODevice::IODevice(uint8_t p)
{
    pin = p;
}
