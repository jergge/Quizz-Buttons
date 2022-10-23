#include "GameManager.h"
#include "UpdateableObject.h"
#include "Arduino.h"

//max number of player is 6 (uses digital pins 2-13)
const int numberOfPlayers = 2;

Quizzmaster *master = nullptr;
GameManager *GM = nullptr;

void setup() 
{
    Serial.begin(115200);
    Serial.println(" ");
    Serial.println("Performing initial setup......... ");
    Serial.println(" ");

    master = new Quizzmaster(A0, A1);
    GM = new GameManager(numberOfPlayers, master);

    //UpdateableObject * test = new UpdateableObject();

  GM->Setup();
  //UpdateableObject::VerifyObjects();

    Serial.println(" ");
    Serial.println("Setup Complete!");
    Serial.println(" ");
    //Serial.println(" ");

  GM->NewRound();
}

void loop() 
{
  GM->Update();
  UpdateableObject::VerifyObjects();
  //UpdateableObject::CallUpdates();
}