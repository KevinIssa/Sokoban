#ifndef _LIGHT_BLOCK_H
#define _LIGHT_BLOCK_H
#include "block.h"

class light_block: public Block
{
public:
  // Constructor
  Light_block(vector_2D center, int width, int height): center{center},width{width},height{height}{}
  ~light_block()=default;

  void draw();

  virtual bool push(const int from)override{
    return true;
  }

  virtual void move()override;
};

#endif