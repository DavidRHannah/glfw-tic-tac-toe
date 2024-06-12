#include "../include/gameLayer/game.h"

Game::Game()
{
    this->mStateManager = new StateManager();
}
Game::~Game()
{
    delete this->mStateManager;
}
void Game::start() 
{
    while (mStateManager->isRunning())
    {
        // Receive and validate input
        int x = 0, 
            y = 0;
        
        // Update board state
        char currentPlayerCharacter = mStateManager->getTurnManager()->getPlayer();
        mStateManager->getBoard()->mark(x, y, currentPlayerCharacter);
        
        // Check for win or draw
        mStateManager->getGameOver()->updateGameState(mStateManager->getBoard(), mStateManager->getTurnManager());

        if (!mStateManager->getGameOver()->isRunning())
        {
            if (mStateManager->getGameOver()->getWinner() != ' ')
            {
                std::cout << "Player " << mStateManager->getGameOver()->getWinner() << " wins!" << std::endl;
            }
            else
            {
                std::cout << "It's a draw!" << std::endl;
            }
        }

        // Update turn manager
        mStateManager->getTurnManager()->incrementTurn();
    }   
}
