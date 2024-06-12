#pragma once
#include "board.h"
#include "turnManager.h"
#include "gameOver.h"

class StateManager
{
    private:
        Board*          mGameBoard;
        TurnManager*    mTurnManager;
        GameOver*       mGameOver;
    public:
        StateManager();
        ~StateManager();
        Board* getBoard();
        TurnManager* getTurnManager();
        GameOver* getGameOver();
        bool isRunning() const;
};

