#include <stdlib.h>
#include <stdio.h>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <iostream>
using namespace std;

struct tup
{
  int x,y;
};

void test(){
  cout<<"ca marche"<<endl;
}
class Text{
  string s;
  tup center;
  int fontSize;
  Fl_Color color;

  public:
  Text(string s, tup center, int fontSize = 10, Fl_Color color = FL_BLACK):
    s{s}, center{center}, fontSize{fontSize}, color{color} {}

  void setString(const string &newString) {
    s = newString;
  }

  void draw() {
    fl_color(color);
    fl_font(FL_HELVETICA, fontSize);
    int width, height;
    fl_measure(s.c_str(), width, height, false);
    fl_draw(s.c_str(), center.x-width/2, center.y-fl_descent()+height/2);
  }
};

class Rectangle {
  tup center;
  int w, h;
  Fl_Color fillColor;
 public:
  Rectangle(tup center, int w, int h,
            Fl_Color frameColor = FL_BLACK,
            Fl_Color fillColor = FL_WHITE);
  void draw();
  bool contains(tup p);
};

Rectangle::Rectangle(tup center, int w, int h,
                     Fl_Color frameColor,
                     Fl_Color fillColor):
  center{center}, w{w}, h{h}, fillColor{fillColor}{}

void Rectangle::draw(){
  fl_draw_box(FL_FLAT_BOX, center.x-w/2, center.y-h/2, w, h, fillColor);
}

bool Rectangle::contains(tup p) {
  return p.x >= center.x-w/2 &&
         p.x < center.x+w/2 &&
         p.y >= center.y-h/2 &&
         p.y < center.y+h/2;
};

class Button{
  Rectangle rec;
  Text text;
  bool on= false;
  public:
  Button(tup center, int w, int h);

  void draw(){
    rec.draw();
  }

  void mouseClick(tup mouseLoc) {
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

Button::Button(tup center, int w, int h):
  rec(center, w, h, FL_BLACK, FL_WHITE),
  text("this is a button",center,h/2){}

class Canvas{
  Button button;
  public:
  Canvas();
  void draw(){
    button.draw();
  }
  void mouseClick(tup mouseLoc){
    button.mouseClick(mouseLoc);
  }
};

class Game_window : public Fl_Window {
  Canvas canvas;
  public:
      Game_window() : Fl_Window (500, 500, 500, 500, "button"){
        Fl::add_timeout(1.0/60, Timer_CB, this);
        resizable(this);
      }   
      void draw() override //call FREQ/sec
      {   
        Fl_Window::draw();
        canvas.draw();
      }

      int handle(int event) override {
          switch (event) 
          {
            case FL_PUSH:
              canvas.mouseClick(tup{Fl::event_x(), Fl::event_y()});
              return 1;
          }
          return 0;
      }
      static void Timer_CB(void *userdata) 
      {
          Game_window *o = static_cast<Game_window*>(userdata);
          o->redraw();
          Fl::repeat_timeout(1.0/60, Timer_CB, userdata);
      }
};

int main(int argc, char *argv[]) {
  Game_window window;
  window.show(argc, argv);
  return Fl::run();
}