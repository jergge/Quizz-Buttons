#include <Arduino.h>

class Led 
{
    public:
        Led(int pinNumber);
        void Update();
        void On();
        void Off();
        void Blink(int delayMS, bool startOn = true);
        void StopBlink();

    protected:
        void TurnOn();
        void TurnOff();
        void Flip();
        int pin;
        bool output;
        bool blinking = false;
        int blinkDelay;
        unsigned long nextBlinkChange;
};