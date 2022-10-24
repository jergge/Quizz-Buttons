#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin) : IODevice(pin)
{
   pinMode(pin, OUTPUT); 
   digitalWrite(pin, LOW);
    Serial.print("Registered a Buzzer on pin ");
        Serial.println(pin);
}

void Buzzer::Update()
{
    //Off();
    if (nextPulse <= millis())
    {
        Flip();
        nextPulse += pulseDelayMS;
        Serial.println("Buzzer flipping");
        Serial.println(millis()); 
        Serial.println(nextPulse);
    }
}

void Buzzer::Flip()
{
    if(on)
    {
        Off();
    } else
    {
        On();
    }
}

void Buzzer::Off()
{
    digitalWrite(pin, LOW);
    on = false;
}

void Buzzer::On()
{
    digitalWrite(pin, HIGH);
    on = true;
}