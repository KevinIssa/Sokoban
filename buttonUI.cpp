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

#include "controller.hpp"
#include "buttonUI.hpp"

using namespace std;

void ButtonUI::draw(){

    fl_draw_box(FL_FLAT_BOX, posx, posy, sizex, sizey , color);
    fl_font(FL_HELVETICA,font_size);
    fl_color(fl_rgb_color(0,0,255));
    /* sprintf(texte,"BEST = %d", value); */
    fl_draw(texte, posx, posy, sizex, sizey ,FL_ALIGN_CENTER,nullptr,false);

}

void ButtonUI::test(){
  cout<<"test"<<endl;
  
}


/* void Clickable_Button::draw(){ */

/* } */



/* void Clickable_ButtonUI::mouseClick(Vector2D mouseLoc){ */

/*     cout<<"CLICK"<<endl; */
/* } */

void Reset_ButtonUI::mouseClick(Vector2D mouseLoc) {
  if (contains(mouseLoc)) {
/* cout<<"reset"<<endl; */
controller->reset_game();
    /* soko->reset_level(); */
    /* soko->fill_box_list(); */
}
}


void Quit_ButtonUI::mouseClick(Vector2D mouseLoc){

if (contains(mouseLoc)) {
  controller->quit_game();
/* cout<<"quit"<<endl; */
}
}

void Previous_level_ButtonUI::mouseClick(Vector2D mouseLoc){


  if (contains(mouseLoc)) {
cout<<"chg lvl"<<endl;
    controller->change_lvl(-1);
  }
}
void Next_level_ButtonUI::mouseClick(Vector2D mouseLoc){


  if (contains(mouseLoc)) {
/* cout<<"chg lvl"<<endl; */
    controller->change_lvl(1);
  }
}


void Reset_all_ButtonUI::mouseClick(Vector2D mouseLoc){

  if (contains(mouseLoc)) {
    controller->reset_all_data();
cout<<"reset_all"<<endl;
}
}

bool Clickable_ButtonUI::contains(Vector2D p) {
  return p.x >= getposx() &&
         p.x < getposx()+getsizex() &&
         p.y >= getposy() &&
         p.y < getposy()+getsizey();
}

/* void Cell::mouseClick(Point mouseLoc) { */
/*   if (r.contains(mouseLoc)) { */
/*     on = !on; */
/*     if (on) */
/*       r.setFillColor(FL_YELLOW); */
/*     else */
/*       r.setFillColor(FL_WHITE); */
/*   } */
/* } */
