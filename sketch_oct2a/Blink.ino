#include "GameManager.h"
#include "UpdateableObject.h"
#include "Arduino.h"
#include "Buzzer.h"

//max number of player is 6 (uses digital pins 2-13, each player need 2 pins)
const int MaxNumberOfPlayers = 5;

Quizzmaster *master = nullptr;
GameManager *GM = nullptr;
Buzzer *buzzer = nullptr;


void setup() 
{
    Serial.begin(115200);
    Serial.println(" ");
    Serial.println("Performing initial setup......... ");
    Serial.println(" ");

    master = new Quizzmaster(A0, A1);
    GM = new GameManager(MaxNumberOfPlayers, master);
    buzzer = new Buzzer(13);

  GM->Setup();

    Serial.println(" ");
    Serial.println("Setup Complete!");
    Serial.println(" ");
    //Serial.println(" ");

}

void loop() 
{
  GM->Update();
  UpdateableObject::CallUpdates();
}