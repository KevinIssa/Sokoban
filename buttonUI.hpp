#ifndef _BUTTONUI_H
#define _BUTTONUI_H


/* #include "controller.hpp" */
/* #include "sokoban.hpp" */
#include "case.hpp"
#include <cstring>
#include <iostream>
#include <iterator>
#include <iterator>

class Controller;

class ButtonUI  {
    private:
        Fl_Color color;
        int posx, posy, sizex, sizey, font_size;
        char texte[20];
        /* int font_size; */
    
    public:
    ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20] ) : color{color},posx{posx}, posy{posy}, sizex{sizex}, sizey{sizey}, font_size{font_size}{std::strcpy(texte, new_texte);}
    ~ButtonUI() = default;
        /* void mouseClick(Vector2D mouseLoc); */
        void draw();
        void test();
        /* void foo(){std::cout<<"dans l'objet: "<<texte<<std::endl;} */

        int getposx(){return posx;}
        int getposy(){return posy;}
        int getsizex(){return sizex;}
        int getsizey(){return sizey;}
        

};


class Clickable_ButtonUI : public ButtonUI  {
    protected:
        Controller *controller;
        /* Fl_Color color; */
        /* int posx, posy, sizex, sizey; */
        /* char score[10]=""; */
    
    public:
        /* using ButtonUI::ButtonUI; */
        /* Clickable_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20]) : ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte}{} */
        Clickable_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller *controller) : ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte}, controller{controller}{}
        ~Clickable_ButtonUI() = default;
       virtual void mouseClick(Vector2D mouseLoc)=0 ;
        void draw();

        bool contains(Vector2D p);

        

};


class Quit_ButtonUI : public Clickable_ButtonUI  {
    private:
        /* Fl_Color color; */
        /* int posx, posy, sizex, sizey; */
        /* char score[10]=""; */
    
    public:
        /* using ButtonUI::ButtonUI; */
        Quit_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        ~Quit_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc) override;
        /* void draw(); */

        /* bool contains(Vector2D p); */

        

};


class Reset_ButtonUI : public Clickable_ButtonUI  {
    private:
        /* Fl_Color color; */
        /* int posx, posy, sizex, sizey; */
        /* char score[10]=""; */
    
    public:
        /* using ButtonUI::ButtonUI; */
        Reset_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        /* Reset_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20]) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte}{} */
        ~Reset_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc) override;
        /* void draw(); */

        /* bool contains(Vector2D p); */

        

};

class Previous_level_ButtonUI : public Clickable_ButtonUI  {
    private:
        /* Fl_Color color; */
        /* int posx, posy, sizex, sizey; */
        /* char score[10]=""; */
    
    public:
        /* using ButtonUI::ButtonUI; */
        /* Chg_lvl_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20]) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte}{} */
        Previous_level_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        ~Previous_level_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc);
        /* void draw(); */

        /* bool contains(Vector2D p); */

        

};

class Next_level_ButtonUI : public Clickable_ButtonUI  {
    private:
        /* Fl_Color color; */
        /* int posx, posy, sizex, sizey; */
        /* char score[10]=""; */
    
    public:
        /* using ButtonUI::ButtonUI; */
        /* Chg_lvl_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20]) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte}{} */
        Next_level_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        ~Next_level_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc);
        /* void draw(); */

        /* bool contains(Vector2D p); */

        

};
class Reset_all_ButtonUI : public Clickable_ButtonUI  {
    private:
        /* Fl_Color color; */
        /* int posx, posy, sizex, sizey; */
        /* char score[10]=""; */
    
    public:
        /* using ButtonUI::ButtonUI; */
        /* Reset_all_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20]) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte}{} */
        Reset_all_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        ~Reset_all_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc);
        /* void draw(); */

        /* bool contains(Vector2D p); */

        

};


/*  class Clickable_Button : public Button  { / */
/*     private: / */
/*           Fl_Color color; 1// */
/*           int posx, posy, sizex, sizey; 1// */
/*           char score[10]=""; 1// */

/*      public: / */
/*          Button(Fl_Color color, int posx, int posy, int sizex, int sizey) : color{color},posx{posx}, posy{posy}, sizex{sizex}, sizey{sizey}{} 1// */
/*           ~Button() = default; 1// */
/*          void mouseClick(Vector2D mouseLoc); / */
/*          void draw(); *1/ */














#endif
