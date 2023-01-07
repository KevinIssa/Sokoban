#include "buttons.hpp"


void Button::draw(){

    fl_draw_box(FL_FLAT_BOX, posx, posy, sizex, sizey , color);
    fl_font(FL_HELVETICA,font_size);
    fl_color(fl_rgb_color(0,0,255));
    /* sprintf(texte,"BEST = %d", value); */
    fl_draw(texte, posx, posy, sizex, sizey ,FL_ALIGN_CENTER,nullptr,false);




}



void Clickable_Button::draw(){

}



void Clickable_Button::mouseClick(Vector2D mouseLoc){

}


