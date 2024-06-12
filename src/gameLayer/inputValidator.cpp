#include "../include/gameLayer/inputValidator.h"

bool InputValidator::validateInput(int x, int y, Board* board)
{
    if (x < 0 || x > 2 || y < 0 || y > 2)
    {
        std::cout << "Coordinates are out of bounds. Please enter a value between 0 and 2 for both row and column." << std::endl;
        return false;
    }
    
    if (board->isMarked(x, y))
    {
        std::cout << "Cell is already marked. Please choose another cell." << std::endl;
        return false;
    }

    return true;
}
