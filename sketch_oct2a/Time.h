#include <Arduino.h>

class Time
{
private:
    int lastUpdate;
public:
    Time(/* args */);
    void Update();

    int time;
    int deltaTime;
};



