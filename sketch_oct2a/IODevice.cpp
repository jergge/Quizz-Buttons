#include "IODevice.h"

void IODevice::Enable()
{
    enabled = true;
}

void IODevice::Disable()
{
    enabled = false;
}

IODevice::IODevice(int p)
{
    pin = p;
}
