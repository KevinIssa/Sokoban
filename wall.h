#ifndef _WALL_H
#define _WALL_H
#include "Block.h"

class Wall : public Block
{
 public:
  // Constructor
  Wall(vector_2D center, int w, int h);
  bool push (const int from) override;
}



#endif