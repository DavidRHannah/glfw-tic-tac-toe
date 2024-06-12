#pragma once
class TurnManager
{
    private:
        unsigned int    mCounter;
        char            mPlayer;
    public:
        TurnManager();
        void incrementTurn() ;
        void reset();
        char getPlayer() const;
        unsigned int getTurnCount() const;
};
