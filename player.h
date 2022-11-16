#ifndef _PLAYER_H
#define _PLAYER_H
#include "Block.h"

class player:public Block
{
private:
    /* data */
public:
    Player(vector_2D center, int width, int height);
    ~player()=default;
};

#endif