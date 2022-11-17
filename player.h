#ifndef _PLAYER_H
#define _PLAYER_H
#include "block.h"

class player:public Block
{
private:
    #define NORTH = 0;
    #define EAST = 1;
    #define SOUTH = 2;
    #define WEST = 3;
    int push_direction = 0;

public:
    Player(vector_2D center, int width, int height);
    ~player()=default;

    int player_input(int &push_direction);
    
};

#endif