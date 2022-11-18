#include "Rectangle.h"


void Rectangle::setFillColor(Fl_Color newFillColor){
  fillColor=newFillColor;
}

void Rectangle::setFrameColor(Fl_Color newFrameColor){
  frameColor=newFrameColor;
};

void Rectangle::setWidth(int new_width) {
  width = new_width;
}

void Rectangle::setHeight(int new_height) {
  height = new_height;
}


bool Rectangle::contains(vector_2D dot){
  return dot.x >= center.x-width/2 &&
         dot.x < center.x+width/2 &&
         dot.y >= center.y-height/2 &&
         dot.y < center.y+height/2;
}

Rectangle::Rectangle(vector_2D center,
                     Fl_Color frameColor,
                     Fl_Color fillColor):
  center{center},fillColor{fillColor}, frameColor{frameColor} {}

void Rectangle::draw() {
  fl_draw_box(FL_FLAT_BOX, center.x-w/2, center.y-h/2, w, h, fillColor);
  fl_draw_box(FL_BORDER_FRAME, center.x-w/2, center.y-h/2, w, h, frameColor);
}











