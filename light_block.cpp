#include "block.h"

class Light_block : public Block
{
 public:
  // Constructor
  Light_block(vector_2D center, int w, int h);
}

Light_bloc::Light_block (vector_2D center, int w, int h):
    r(center, w, h, FL_GREEN, FL_GREEN)

