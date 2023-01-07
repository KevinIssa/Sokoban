#include <stdlib.h>
#include <stdio.h>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>
using namespace std;

void test(){
  cout<<"ca marche"<<endl;
}
class Text{
  string str;
  Vector2D center;
  int fontSize;
  Fl_Color color;

  public:
  Text(string str, Vector2D center, int fontSize = 10, Fl_Color color = FL_BLACK):
    str{str}, center{center}, fontSize{fontSize}, color{color} {}

  void setString(const string &newString) {
    str = newString;
  }

  void draw() {
    fl_color(color);
    fl_font(FL_HELVETICA, fontSize);
    int width, height;
    fl_measure(str.c_str(), width, height, false);
    fl_draw(str.c_str(), center.x-width/2, center.y-fl_descent()+height/2);
  }
};

class Rectangle {
  Vector2D center;
  int width, height;
  Fl_Color fillColor;
 public:
  Rectangle(Vector2D center, int width, int height,
            Fl_Color frameColor = FL_BLACK,
            Fl_Color fillColor = FL_WHITE);
  void draw();
  bool contains(Vector2D dot);
};

Rectangle::Rectangle(Vector2D center, int width, int height,
                     Fl_Color frameColor,
                     Fl_Color fillColor):
  center{center}, width{width}, height{height}, fillColor{fillColor}{}

void Rectangle::draw(){
  fl_draw_box(FL_FLAT_BOX, center.x-width/2, center.y-width/2, width, height, fillColor);
}

bool Rectangle::contains(Vector2D dot) {
  return dot.x >= center.x-width/2 &&
         dot.x < center.x+width/2 &&
         dot.y >= center.y-height/2 &&
         dot.y < center.y+height/2;
};

class Button{
  Rectangle rec;
  Text text;
  bool on= false;
  public:
  Button(Vector2D center, int w, int h, string text);

  void draw(){
    rec.draw();
    text.draw();
  }

  void mouseClick(Vector2D mouseLoc) {
   if (rec.contains(mouseLoc)) {
    on = !on;
    if (on){
      text.setString("button clicked");
      text.draw();
    }
    else{
      test();
    }
    }
  }
};

Button::Button(Vector2D center, int width, int height, string text):
  rec(center, width, height, FL_BLACK, FL_WHITE),
  text(text, center, h/2) {}
