#include "../include/gameLayer/stateManager.h"

StateManager::StateManager() 
{
    this->mGameBoard = new Board();
    this->mTurnManager = new TurnManager();
    this->mGameOver = new GameOver();
}
StateManager::~StateManager()
{
    delete this->mGameBoard;
    delete this->mTurnManager;
    delete this->mGameOver;
}
Board* StateManager::getBoard()
{
    return this->mGameBoard;
}
TurnManager* StateManager::getTurnManager()
{
    return this->mTurnManager;
}
GameOver* StateManager::getGameOver()
{
    return this->mGameOver;
}

bool StateManager::isRunning() const
{
    return this->mGameOver->isRunning();
}