#include "../include/gameLayer/board.h"

Board::Board() 
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++) 
        {
            this->mBoard[row][col] = ' ';
        }
    }
}
bool Board::mark(unsigned int row, unsigned int col, char marker)
{
    if (row > 2 || col > 2) 
    {
        throw std::invalid_argument("Invalid row and/or column value");
        return false;
    }
    if (std::toupper(marker) != 'O' && std::toupper(marker) != 'X')
    {
        throw std::invalid_argument("Invalid marker value");
        return false;
    }
    if (getMarker(row, col) != ' ')
    {
        throw std::invalid_argument("Previously marked point");
        return false;
    }
    else
    {
        this->mBoard[row][col] = marker;
        return true;
    }
}

bool Board::isMarked(unsigned int row, unsigned int col) const
{
    if (row > 2 || col > 2) 
    {
        throw std::invalid_argument("Invalid row and/or column value");
    }
    if (this->mBoard[row][col] == 'O' || this->mBoard[row][col] == 'X') 
    {
        return true;
    }
    
    return false;
}

char Board::getMarker(unsigned int row, unsigned int col) const
{
    if (row > 2 || col > 2) 
    {
        throw std::invalid_argument("Invalid row and/or column value");
    }
    return this->mBoard[row][col];
}