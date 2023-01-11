#ifndef _PLAYER_H
#define _PLAYER_H

#include "case.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>

using namespace std;

class Player : public Case
{
    public:
        Player(char value, Vector2D pos, Fl_Color col): Case(value, pos, col){}
        
};

#endif
