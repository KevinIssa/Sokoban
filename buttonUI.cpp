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

    fl_draw(texte, posx, posy, sizex, sizey ,FL_ALIGN_CENTER,nullptr,false);

}

void Reset_ButtonUI::mouseClick(Vector2D mouseLoc) {
  if (contains(mouseLoc)) {

    controller->reset_game();
      
  }
}


void Quit_ButtonUI::mouseClick(Vector2D mouseLoc){

  if (contains(mouseLoc)) {
    controller->quit_game();
  }
}

void Previous_level_ButtonUI::mouseClick(Vector2D mouseLoc){

  if (contains(mouseLoc)) {
    controller->change_lvl(-1);
  }

}

void Next_level_ButtonUI::mouseClick(Vector2D mouseLoc){


  if (contains(mouseLoc)) {

    controller->change_lvl(1);
  }
}

void Reset_all_ButtonUI::mouseClick(Vector2D mouseLoc){

  if (contains(mouseLoc)) {
    controller->reset_all_data();
  }

}

bool Clickable_ButtonUI::contains(Vector2D dot) {
  
  return dot.x >= getposx() &&
         dot.x < getposx()+getsizex() &&
         dot.y >= getposy() &&
         dot.y < getposy()+getsizey();
}
