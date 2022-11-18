#ifndef _BLOCK_H
#define _BLOCK_H
#include "Rectangle.h"

class Block
{
private:
   Rectangle r;

public:
    Block(vector_2D center, int width, int height):center{center},width{width},height{height}{}
    ~Block()=default

    // Methods that draw 
    void draw();

    virtual bool push(const int from){
        return true;
    }

    virtual void move();
};

#endif