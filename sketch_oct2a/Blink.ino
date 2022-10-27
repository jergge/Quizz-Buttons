#include "GameManager.h"
#include "UpdateableObject.h"
#include "Arduino.h"
#include "Buzzer.h"

//max number of player is 6 (uses digital pins 2-13, each player need 2 pins)
const int MaxNumberOfPlayers = 2;

Quizzmaster *master = nullptr;
GameManager *GM = nullptr;
Buzzer *buzzer = nullptr;


void setup() 
{
  
    Serial.begin(9600);
    Serial.println(" ");
    Serial.println(F("Performing initial setup......... "));
    Serial.println(" ");
    master = new Quizzmaster(30, 31);
    //buzzer = new Buzzer(13);
    GM = new GameManager(MaxNumberOfPlayers, master);

  GM->Setup();

    Serial.println(" ");
    Serial.println(F("Setup Complete!"));
    Serial.println(" ");
    //Serial.println(" ");

}

void loop() 
{
  UpdateableObject::CallUpdates();
  GM->Update();
}