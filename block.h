#ifndef _BLOCK_H
#define _BLOCK_H
#include "Rectangle.h"

class Block
{
private:
   Rectangle r;

public:
    virtual Block(vector_2D center, int width, int height);

    // Methods that draw 
    void draw();

    virtual bool push(const int from);

    virtual void move();
};

#endif