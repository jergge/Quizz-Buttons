#include "GameManager.h"

GameManager::GameManager(int playerCount, Quizzmaster* inMaster)
{
    numberOfPlayers = playerCount; 
    master = inMaster;
}

void GameManager::Setup()
{
    //initialise the size of the player array
        Player *t;
        t = new Player[(sizeof(Player))*numberOfPlayers];
        //and assign the pointer to the array to the class member
        playerArray = &t;

    //create each of the players
    //we assume that the physical connections are from the lowest number and in ascending order (for now)
        for (int i = 0; i < numberOfPlayers; i++)
        {
            playerArray[i] = new Player(i);
        }

    NewRound();
}

void GameManager::Update()
{
    if (state == 0)
    {
        WaitingForPlayers();
    } else if (state == 1)
    {
        WaitingForMaster();
    }
}

void GameManager::WaitingForPlayers()
{
    //see if any players have pushed their buttons (disabled players will always return false)
    //keep looping until one is pressed
    for (int i = 0; i < numberOfPlayers; i++)
    {
        if (playerArray[i]->ButtonPushed())
        {
            AwaitingAnswerFrom(i);
            playerArray[i]->LedEnable();
            //DisableAllPlayersExcept(i);
            state = 1;
            Serial.println(" ");
            break;
        }
    }
}

void GameManager::AwaitingAnswerFrom(int playerID)
{
    playerAnswering = playerID;
    Serial.println(" ");
    Serial.print("Awaiting an answer from player ");
        Serial.println(playerID);
}

void GameManager::WaitingForMaster()
{
    if (master->No())
    {
        //Serial.println(" ");
        Serial.println("Oh no! That was the wrong answer... ");
        playerArray[playerAnswering]->LedDisable();
        playerArray[playerAnswering]->Disable();
        ReopenRound();
    } else if (master->Yes())
    {
        Serial.println("Correct answer given. Well Done!");
        playerArray[playerAnswering]->LedDisable();
        NewRound();
    }
}

void GameManager::ReopenRound()
{
    state = 0;
    Serial.println(" ");
    Serial.println("Reopening round for remaining players ");
    Serial.println(" ");
}

void GameManager::NewRound()
{
    delay(200);
    Serial.println(" ");
    Serial.println("New Game round! (new question to answer) ");
    Serial.println(" ");
    EnableAllPlayers();


    //set the sate to 0
    state = 0;
}

void GameManager::DisableAllPlayersExcept(int id)
{
    for ( int i = 0; i < numberOfPlayers; i++)
    {
        if(i != id)
        {
            playerArray[i]->Disable();
        }
    }
}

void GameManager::EnableAllPlayers()
{
     //enable all the players (default is false in the class)
    for (int i = 0; i<numberOfPlayers; i++)
    {
        playerArray[i]->Enable();
    }
}