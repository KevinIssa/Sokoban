#include "block.h"
//abstract class of a block (Wall, Player, ...)

Block::Block(vector_2D center ,int width, int height):
  center{center}, width{width}, height{height} {}

void Block::draw() {
  r.draw();

}

bool Block::push(const int from){ // if the block can be push default yes
  return true;
}

void Block::move(){

}
