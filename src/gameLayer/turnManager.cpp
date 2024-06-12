#include "../include/gameLayer/turnManager.h"

TurnManager::TurnManager() : mCounter(0), mPlayer('O') {}
void TurnManager::incrementTurn() 
{
    this->mCounter++;
    switch (this->mPlayer)
    {
        case 'O':
            this->mPlayer = 'X';
            break;
        case 'X':
            this->mPlayer = 'O';
            break;
    }
}
void TurnManager::reset() 
{
    this->mCounter = 0;
    this->mPlayer = 'O';
}
char TurnManager::getPlayer() const
{
    return this->mPlayer;
}
unsigned int TurnManager::getTurnCount() const 
{
    return this->mCounter;
}
