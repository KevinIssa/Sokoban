#include "wall.h"


Wall::Wall (vector_2D center, int w, int h):
    r(center, w, h, FL_BLACK,  FL_BLACK){}


Wall::push(const int from){ // if the block can be push default yes  
    return false;
}