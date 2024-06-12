#pragma once
#include <string>
#include <cassert>
#include <stdexcept>
#include <stdlib.h>

class Board 
{
    private:
        char mBoard[3][3];
    public:
        Board();
        bool mark(unsigned int row, unsigned int col, char marker);
        bool isMarked(unsigned int row, unsigned int col) const;
        char getMarker(unsigned int row, unsigned int col) const;
};
