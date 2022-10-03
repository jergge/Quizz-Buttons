#include "MomentaryButton.h"

MomentaryButton::MomentaryButton(int p) : IODevice(p)
{
    pinMode(p, INPUT);
}

void MomentaryButton::Update()
{
    if (digitalRead(pin) == HIGH)
    {   
        Serial.print("button down     ");
    } else if(digitalRead(pin) == LOW)
    {
        Serial.print("Not Pressed      ");
    }
}

void MomentaryButton::RegisterOnPressed(Led * index)
{
    if(registeredIndex < maxRegistered)
    {
        registeredOnPressed[registeredIndex] = index;
        index++;
    }
}

void MomentaryButton::OnPressed()
{

}
