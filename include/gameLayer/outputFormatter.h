#pragma once
#include <iostream>
#include "stateManager.h"

class OutputFormatter
{
    private:
        void outputTurnInfo(const TurnManager* tm) const;
        void outputBoard(const Board* b) const;
        void clear() const;
    public:
        void outputGame(StateManager* sm);
};

