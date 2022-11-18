#ifndef _WALL_H
#define _WALL_H
#include "block.h"

class Wall : public Block
{
 public:
  // Constructor
  Wall(vector_2D center, int width, int height):center{center},width{width},height{height}{}
  ~Wall()=default;

  bool push (const int from) override{
    return false;
  }
};



#endif