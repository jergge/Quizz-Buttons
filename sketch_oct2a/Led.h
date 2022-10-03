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
        void Enable();
        void Disable();

    protected:
        void TurnOn();
        void TurnOff();
        void Flip();
        int pin;
        bool output;
        bool blinking = false;
        bool enabled = true;
        int blinkDelay;
        unsigned long nextBlinkChange;
};