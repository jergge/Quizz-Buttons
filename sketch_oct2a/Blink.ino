#include "includes.h"

int redPin = 2;
int buttonPin = 6;

Led red(redPin);
MomentaryButton button(buttonPin);

void setup() 
{
  Serial.begin(115200);
  red.Blink(500);
}

void loop() 
{

  red.Update();
  //red.Disable();

}