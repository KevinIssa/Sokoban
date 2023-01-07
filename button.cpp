#
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>

#include "button.hpp"

using namespace std;

void Button::draw(){

    fl_draw_box(FL_FLAT_BOX, posx, posy, sizex, sizey , color);
    fl_font(FL_HELVETICA,font_size);
    fl_color(fl_rgb_color(0,0,255));
    /* sprintf(texte,"BEST = %d", value); */
    fl_draw(texte, posx, posy, sizex, sizey ,FL_ALIGN_CENTER,nullptr,false);

}

void Button::test(){
  cout<<"test"<<endl;
  
}


/* void Clickable_Button::draw(){ */

/* } */



/* void Clickable_Button::mouseClick(Vector2D mouseLoc){ */

/* } */


