
#include "includes.h"

const int deviceSize = 3;

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
  Led * green = new Led(greenPin);
  MomentaryButton * testButton = new MomentaryButton(buttonPin);
  // leds[1] = new Led(greenPin);
  // buttons[0] = new MomentaryButton(buttonPin);
  // buttons[1] = new MomentaryButton(otherButtonPin);

  dev[0] = red;
  dev[1] = green;
  dev[2] = testButton;
  //dev[3] = new MomentaryButton(otherButtonPin);

  Serial.begin(115200);

  testButton->RegisterOnPressed(red);
  testButton->RegisterOnPressed(green);

  //red->On();

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