#include<tuple>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>



struct vector_2D {
  int x, y;
};

class Rectangle {
  vector_2D center;
  int w=10, h=10;
  // int w, h;

  Fl_Color fillColor, frameColor;

 public:
  Rectangle(vector_2D center, int w, int h,
            Fl_Color frameColor,
            Fl_Color fillColor);

  void draw();

  void setFillColor(Fl_Color newFillColor);

  Fl_Color getFillColor() {
    return fillColor;
  }

  void setFrameColor(Fl_Color newFrameColor);
  Fl_Color getFrameColor() {
    return frameColor;
  }

  void setWidth(int neww) {
    w = neww;
  }

  void setHeight(int newh) {
    h = newh;
  }

  int getWidth() {
    return w;
  }

  int getHeight() {
    return h;
  }

  bool contains(Point p);

  vector_2D getCenter() {
    return center;
  }
};

Rectangle::Rectangle(vector_2D center,
                     Fl_Color frameColor,
                     Fl_Color fillColor):
  center{center},fillColor{fillColor}, frameColor{frameColor} {}
  // center{center}, w{10}, h{10}, fillColor{fillColor}, frameColor{frameColor} {}

void Rectangle::draw() {
  fl_draw_box(FL_FLAT_BOX, center.x-w/2, center.y-h/2, w, h, fillColor);
  fl_draw_box(FL_BORDER_FRAME, center.x-w/2, center.y-h/2, w, h, frameColor);
}











