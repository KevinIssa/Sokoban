#ifndef _BUTTON_H
#define _BUTTON_H



#include "case.hpp"
#include <FL/Enumerations.H>
class Button  {
    private:
        Fl_Color color;
        int posx, posy, sizex, sizey, font_size;
        char texte[20];
        /* int font_size; */
    
    public:
        Button(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char texte[20] ) : color{color},posx{posx}, posy{posy}, sizex{sizex}, sizey{sizey}, font_size{font_size},texte{texte[20] }{}
        ~Button() = default;
        /* void mouseClick(Vector2D mouseLoc); */
        void draw();

        

};


class Clickable_Button : public Button  {
    private:
        /* Fl_Color color; */
        /* int posx, posy, sizex, sizey; */
        /* char score[10]=""; */
    
    public:
        /* Button(Fl_Color color, int posx, int posy, int sizex, int sizey) : color{color},posx{posx}, posy{posy}, sizex{sizex}, sizey{sizey}{} */
        /* ~Button() = default; */
        void mouseClick(Vector2D mouseLoc);
        void draw();

        

};



















#endif
