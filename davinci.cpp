#include "davinci.h"
#include <windows.h>
#include <iostream>
#include "game.h"
using namespace std;
Davinci::Davinci()
{

}

void Davinci::gotoxy(int x,int y)
{
    HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = static_cast<SHORT>(x);
    coord.Y = (SHORT)y;
    SetConsoleCursorPosition(hndl,coord);
}

void Davinci::draw(const Tank* const pTanks, const int N)
{
    char p;
    for (int i = 0; i<N; ++i) {
        Point coord = pTanks[i].getCoord();
        gotoxy(coord.x,coord.y);
        cout <<'#';
    }
    Sleep(2000);                        //function clear
    for (int i = 0; i<N; ++i) {
        Point coord = pTanks[i].getCoord();
        gotoxy(coord.x,coord.y);
        cout <<" ";
    }
   // gotoxy(0,200);

}
