#ifndef _BUTTON_H
#define _BUTTON_H



/* #include "case.hpp" */
#include <FL/Enumerations.H>
#include <iostream>
#include <iterator>
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
        void test();
        void foo(){std::cout<<"dans l'objet: "<<texte<<std::endl;}

        

};


/* class Clickable_Button : public Button  { */
/*     private: */
/*         /1* Fl_Color color; *1/ */
/*         /1* int posx, posy, sizex, sizey; *1/ */
/*         /1* char score[10]=""; *1/ */
    
/*     public: */
/*         /1* Button(Fl_Color color, int posx, int posy, int sizex, int sizey) : color{color},posx{posx}, posy{posy}, sizex{sizex}, sizey{sizey}{} *1/ */
/*         /1* ~Button() = default; *1/ */
/*         void mouseClick(Vector2D mouseLoc); */
/*         void draw(); */

        

/* }; */



















#endif
