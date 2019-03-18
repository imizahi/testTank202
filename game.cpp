#include "game.h"
#include <iostream>
using namespace std;


Game::Game(): m_isContinue(true)
{
    m_pTanks = amount_tanks(NUM_TANKS);
}

Game::~Game()
{
    deleteTanks(m_pTanks);
}

void Game::start()
{
    char p;
    while (m_isContinue)
    {
        for (int i=0; i<NUM_TANKS; ++i) {
            m_pTanks[i].move();
        }
        m_painter.draw(m_pTanks,NUM_TANKS);
//        cout<<"do you want pause"<<endl;
//        cin>>p;
//        if (p =='y'){
//            stop();
//        }
        //m_pTanks[0].show();
        m_pTanks[0] -= 20;
        m_pTanks[0].show();

    }
}

void Game::stop()
{
    m_isContinue = false;
}
