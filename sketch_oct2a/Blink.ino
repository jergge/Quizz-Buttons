
#include "includes.h"

const int deviceSize = 5;

int redPin = 2;
int greenPin = 4;
//Led** leds = new Led*[2];
// Led red(redPin);
// Led green(greenPin);


int buttonPin = 6;
int otherButtonPin = 7;
//MomentaryButton** buttons = new MomentaryButton*[2];
// MomentaryButton button(buttonPin);
// MomentaryButton otherButton(otherButtonPin);

IODevice** dev = new IODevice*[deviceSize];

void setup() 
{
  // leds[0] = new Led(redPin);
  Led * red = new Led(redPin);
  // leds[1] = new Led(greenPin);
  // buttons[0] = new MomentaryButton(buttonPin);
  // buttons[1] = new MomentaryButton(otherButtonPin);

  dev[0] = new Led(redPin);
  dev[1] = red;
  dev[2] = new Led(greenPin);
  dev[3] = new MomentaryButton(buttonPin);
  dev[4] = new MomentaryButton(otherButtonPin);

  Serial.begin(115200);
  red->Blink(500);
  // red.Disable();
}

void loop() 
{

  for (int i = 0; i < deviceSize; i++)
  {
    dev[i]->Update();
  }

  //leds[0]->Update();
  //red.Disable();

}