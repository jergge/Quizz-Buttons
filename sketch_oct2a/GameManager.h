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
        Player **playerArray;
        Quizzmaster* master;
        // state 0 = waiting for people to buzz (some may be disabled)
        // state 1 = waiting for quizzmaster to respond
        int state;

        void WaitingForPlayers();

        void AwaitingAnswerFrom(int playerID);

        int playerAnswering;

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
        void DisableAllPlayersExcept(int id);
};