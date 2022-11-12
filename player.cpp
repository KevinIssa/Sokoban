#include "block.h"

class Player : public Block
{
 public:
  // Constructor
  Player(vector_2D center, int w, int h);
}

Player::Player (vector_2D center, int w, int h):
    r(center, w, h, FL_WHITE, FL_WHITE)

