#include "GameManager.h"

//max number of player is 6
const int numberOfPlayers = 3;

Quizzmaster *master = new Quizzmaster(0, 1);

GameManager *GM = new GameManager(numberOfPlayers, master);

void setup() 
{
  Serial.begin(115200);
    //Serial.println(" ");
    Serial.println("Performing initial setup......... ");
    //Serial.println(" ");

  GM->Setup();

    Serial.println(" ");
    Serial.println("Setup Complete!");
    //Serial.println(" ");
}

void loop() 
{
  GM->Update();
}