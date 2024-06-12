#pragma once
#include "inputValidator.h"
#include "outputFormatter.h"
#include "stateManager.h"

class Game
{
    private:
        StateManager*       mStateManager;
    public:
        Game();
        ~Game();
        void start();
};