#pragma once
#include "Player.h"
#include "Quizzmaster.h"

class GameManager
{
    public:
        GameManager(int playerCount, Quizzmaster* master);

        //Run once in Main::Setup -> will be expanded with functionality:
        // - ability to dynamically register players
        void Setup();
        
        //Runs every Update loop from Main, contains the main logic of the class
        void Update();
        
        //Launch state 0 with no lockouts
        void NewRound();

    protected:
        //
        int numberOfPlayers; 
        Player * * playerArray = nullptr;
        Quizzmaster * master = nullptr;
        
        // state -1 = waiting for players to hit their buttons to be registered
        // state 0  = waiting for people to buzz (some may be disabled)
        // state 1  = waiting for quizzmaster to respond
        int state;

        //Loop after question has been asked, waiting for players to hit the buttons
        void WaitingForPlayers();

        void AwaitingAnswerFrom(int playerID);

        //Holds the value of the player who hit thier button
        //Used to lock them out if they get the answer wrong
        int playerAnswering;

        //Loop when the question has been answered and awaiting the master's verdict
        void WaitingForMaster();
        

        //Lock the round (while an answer is being given)
        void LockRound();

        //Lock out a player for the round
        void LockOutPlayer(int playerNumber);

        //Reopen the question (same round)
        void ReopenRound();

        void EnableAllPlayers();
        void DisableAllPlayersLedsExcept(int id);

        //Check if all the players have been disabled this round
        //(to avoid waiting for an answer when onbody can answer)
        bool NoActivePlayersRemaining();

        void EnableActivePlayersLeds();
};