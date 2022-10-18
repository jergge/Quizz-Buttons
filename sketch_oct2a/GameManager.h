#pragma once
#include "includes.h"
#include "Player.h"
#include "Quizzmaster.h"

class GameManager
{
    public:
        GameManager(int playerCount, Quizzmaster* master);
        void Setup();
        void Update();

    protected:
        int numberOfPlayers;
        Player **playerArray = nullptr;
        Quizzmaster* master = nullptr;
        // state 0 = waiting for people to buzz (some may be disabled)
        // state 1 = waiting for quizzmaster to respond
        int state;

        //Loop after question has been asked, waiting for players to hit the buttons
        void WaitingForPlayers();

        void AwaitingAnswerFrom(int playerID);

        int playerAnswering;


        //Loop when the question has been answered and awaiting the master's verdict
        void WaitingForMaster();
        
        //Launch state 0 with no lockouts
        void NewRound();

        //Lock the round (while an answer is being given)
        void LockRound();

        //Lock out a player for the round
        void LockOutPlayer(int playerNumber);

        //Reopen the question (same round)
        void ReopenRound();

        void EnableAllPlayers();
        void DisableAllPlayersLedsExcept(int id);

        bool NoActivePlayersRemaining();

        void EnableActivePlayersLeds();
};