#include "rectangle.cpp"
#include<tuple>

struct vector_2D {
  int x, y;
};

//abstract class of a block (Wall, Player, ...)
class Block {
  Rectangle r;

 public:
  // Constructor
  virtual Block(vector_2D center, int w, int h);

  // Methods that draw 
  void draw();
  virtual bool push(const int from);
  virtual void move();
};

// Block::Block(vector_2D center, int w, int h):
//   r(center, w, h, FL_BLACK, FL_WHITE),

void Block::draw() {
    r.draw();

}

virtual bool push(const int from) // if the block can be push default yes
        {
            return true;
        }