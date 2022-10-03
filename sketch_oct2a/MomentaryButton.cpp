#include "MomentaryButton.h"

MomentaryButton::MomentaryButton(int p) : IODevice(p)
{
    pinMode(p, INPUT);
}

void MomentaryButton::Update()
{

}

void OnPressed()
{
    
}
