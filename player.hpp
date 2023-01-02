#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>

using namespace std;

class Player : public Case
{
    public:
        Player(string name, char value, Vector2D pos, Fl_Color col, Fl_Image *im): Case(name,value, pos, col, im){}
        
};

#endif