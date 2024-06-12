#include "../include/gameLayer/outputFormatter.h"

void OutputFormatter::outputTurnInfo(const TurnManager* tm) const
{
    std::cout << "Turn Count: " << tm->getTurnCount() << std::endl;
    std::cout << "Player: " << tm->getPlayer() << std::endl;          
}

void OutputFormatter::outputBoard(const Board* b) const
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++) 
        { 
            std::cout << "  " << b->getMarker(row, col) << "  ";
            if (col != 2)
                std::cout << "|";
        }
        if (row != 2)
            std::cout << std::endl << "_________________";
        std::cout << std::endl << std::endl;
    }
}

void OutputFormatter::clear() const
{
    std::system("clear");
}

void OutputFormatter::outputGame(StateManager* sm) 
{
    Board* board = sm->getBoard();
    TurnManager* turnManager = sm->getTurnManager();
    
    this->clear();
    
    //std::cout << "===================" << std::endl;
    this->outputBoard(board);
    this->outputTurnInfo(turnManager);
    //std::cout << "===================" << std::endl;
}
