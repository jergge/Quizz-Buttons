#include "GameManager.h"


GameManager::GameManager(int playerCount, Quizzmaster* inMaster)
{
    numberOfPlayers = playerCount; 
    master = inMaster;
}

void GameManager::Setup()
{
    //initialise the size of the player array
        // Player *array[numberOfPlayers];
        // playerArray = array;
    playerArray = new Player*[numberOfPlayers];

    //create a pointer for each potential player
    //and store them in the array
        for (int i = 0; i < numberOfPlayers; i++)
        {
            playerArray[i] = new Player(i);
            playerArray[i]->Enable();
            playerArray[i]->ButtonEnable();
            playerArray[i]->LedOff();
        }

    state = -1;
}

void GameManager::NewRound()
{
        Serial.println(" ");
        Serial.println("New Game round! (new question to answer) ");
        Serial.println(" ");
    EnableAllPlayers();

    //set the sate to 0
    state = 0;
}

void GameManager::EnableAllPlayers()
{
    for (int i = 0; i<numberOfPlayers; i++)
    {
        if (playerArray[i]->active)
        {
            playerArray[i]->Enable();
            playerArray[i]->ButtonEnable();
            playerArray[i]->LedOn();
        }
    }
}

void GameManager::Update()
{
    if          (state == 0)
    {
        WaitingForPlayers();
    } else if   (state == 1)
    {
        WaitingForMaster();
    } else if   (state == -1)
    {
        WaitingForRegistrations();
    }
}

void GameManager::WaitingForPlayers()
{
    //see if any players have pushed their buttons (disabled players will always return false)
    //keep looping until one is pressed
    for (int i = 0; i < numberOfPlayers; i++)
    {
        if (playerArray[i]->ButtonPushed() && playerArray[i]->active)
        {
            AwaitingAnswerFrom(i);
            state = 1;
            Serial.println(" ");
            break;
        }
    }
}

void GameManager::AwaitingAnswerFrom(int playerID)
{
    playerAnswering = playerID;
    DisableAllPlayersLedsExcept(playerAnswering);
    playerArray[playerAnswering]->Blink();
    // playerList.Get(playerAnswering).DataPtr()->Blink();
        Serial.println(" ");
        Serial.print("Awaiting an answer from player ");
        Serial.println(playerID);
}

void GameManager::DisableAllPlayersLedsExcept(int id)
{
    for ( int i = 0; i < numberOfPlayers; i++)
    {
        if(i != id && playerArray[i]->active)
        {
            playerArray[i]->LedOff();
        }
    }
}

void GameManager::WaitingForMaster()
{
    if (master->No())
    {
            //Serial.println(" ");
            Serial.println("Oh no! That was the wrong answer... ");
        playerArray[playerAnswering]->Disable();
        playerArray[playerAnswering]->LedOff();
        ReopenRound();
    } else if (master->Yes())
    {
            Serial.println("Correct answer given. Well Done!");
        NewRound();
    }
}

void GameManager::WaitingForRegistrations()
{
    for ( int i = 0; i < numberOfPlayers; i++)
    {
        // Serial.print("polling player ");
        // Serial.println(playerArray[i]->name);
        if (playerArray[i]->ButtonPushed())
        {
            Serial.print("Registering player ");
            playerArray[i]->active = true;
            playerArray[i]->LedOn();
            playerArray[i]->ButtonDisable();
            Serial.println(i);
        }
    }

    if (master->Yes())
    {
        int activePlayerCount = 0;

        for (int i = 0; i < numberOfPlayers; i++)
        {
            if ( playerArray[i]->active )
            {
                activePlayerCount++;
            }
        }

        if (activePlayerCount == 0)
        {
            Serial.println("Cannot start the game with 0 players!");
            return;            
        }
        Serial.print("Starting the game with player count: ");
        Serial.println(activePlayerCount);

        //progress to the game state!
        NewRound();
    }
}

void GameManager::ReopenRound()
{
    if(NoActivePlayersRemaining())
    {
        NewRound();
    } else {
        EnableActivePlayersLeds();
        state = 0;
            Serial.println(" ");
            Serial.println("Reopening round for remaining players ");
            Serial.println(" ");
    }
}

bool GameManager::NoActivePlayersRemaining()
{
    for ( int i = 0; i < numberOfPlayers; i++)
    {
        if ( playerArray[i]->IsEnabled() && playerArray[i]->active )
        {
            return false;
        }
    }
    return true;
}

void GameManager::EnableActivePlayersLeds()
{
    for (int i = 0; i < numberOfPlayers; i++)
    {
        if ( playerArray[i]->IsEnabled() && playerArray[i]->active )
        {
            playerArray[i]->LedOn();
        }
    }
}