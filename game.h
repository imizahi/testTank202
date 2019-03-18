#ifndef GAME_H
#define GAME_H
#include "tank.h"
#include "davinci.h"

const int NUM_TANKS = 10;
class Game
{
    bool m_isContinue; //start game
    Tank* m_pTanks; //pointer to tanks array
    Davinci m_painter;
public:
    void start();
    void stop();
    Game();
    ~Game();
};

#endif // GAME_H
