#include "includes.h"

int redPin = 2;
int greenPin = 4;

Led red(2);

void setup() 
{
  Serial.begin(115200);
  red.Blink(100);

}

void loop() 
{

  red.Update();

}