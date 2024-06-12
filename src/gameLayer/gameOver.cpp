#include "../include/gameLayer/gameOver.h"

GameOver::GameOver()
    : mRunning(true), mWinner(' ')
{}

bool GameOver::isRunning() const
{
    return mRunning;
}

char GameOver::getWinner() const
{
    return mWinner;
}

bool GameOver::checkWin(Board* board, char player) const
{
    const int size = 3;
    for (int i = 0; i < size; ++i)
    {
        // Check rows
        if (board->getMarker(i, 0) == player && board->getMarker(i, 1) == player && board->getMarker(i, 2) == player)
            return true;
        // Check columns
        if (board->getMarker(0, i) == player && board->getMarker(1, i) == player && board->getMarker(2, i) == player)
            return true;
    }
    // Check diagonals
    if (board->getMarker(0, 0) == player && board->getMarker(1, 1) == player && board->getMarker(2, 2) == player)
        return true;
    if (board->getMarker(0, 2) == player && board->getMarker(1, 1) == player && board->getMarker(2, 0) == player)
        return true;

    return false;
}

bool GameOver::checkDraw(Board* board) const
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (!board->isMarked(i, j))
                return false;
        }
    }
    return true;
}

void GameOver::updateGameState(Board* board, TurnManager* turnManager)
{
    char currentPlayer = turnManager->getPlayer();

    if (checkWin(board, currentPlayer))
    {
        mWinner = currentPlayer;
        mRunning = false;
    }
    else if (checkDraw(board))
    {
        mRunning = false;
    }
}