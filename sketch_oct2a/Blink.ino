#include "GameManager.h"

//max number of player is 6 (uses digital pins 2-13)
const int numberOfPlayers = 3;

Quizzmaster *master = nullptr;
GameManager *GM = nullptr;

void setup() 
{
  Serial.begin(115200);
    //Serial.println(" ");
    Serial.println("Performing initial setup......... ");
    Serial.println(" ");

    master = new Quizzmaster(A0, A1);
    GM = new GameManager(numberOfPlayers, master);

  GM->Setup();

    Serial.println(" ");
    Serial.println("Setup Complete!");
    //Serial.println(" ");
}

void loop() 
{
  GM->Update();
}