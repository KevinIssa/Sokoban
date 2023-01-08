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
    
    public:
    ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20] ) : color{color},posx{posx}, posy{posy}, sizex{sizex}, sizey{sizey}, font_size{font_size}{std::strcpy(texte, new_texte);}
    ~ButtonUI() = default;

        void draw();

        int getposx(){return posx;}
        int getposy(){return posy;}
        int getsizex(){return sizex;}
        int getsizey(){return sizey;}
        

};


class Clickable_ButtonUI : public ButtonUI  {
    protected:
        Controller *controller;
    
    public:
        Clickable_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller *controller) : ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte}, controller{controller}{}
        ~Clickable_ButtonUI() = default;

        virtual void mouseClick(Vector2D mouseLoc)=0 ;

        bool contains(Vector2D dot); 

};


class Quit_ButtonUI : public Clickable_ButtonUI  {
    private:
    
    public:

        Quit_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        ~Quit_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc) override;

};


class Reset_ButtonUI : public Clickable_ButtonUI  {

    public:

        Reset_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}

        ~Reset_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc) override;

};

class Previous_level_ButtonUI : public Clickable_ButtonUI  {

    public:

        Previous_level_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        ~Previous_level_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc);

};

class Next_level_ButtonUI : public Clickable_ButtonUI  {

    public:

        Next_level_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        ~Next_level_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc);

};

class Reset_all_ButtonUI : public Clickable_ButtonUI  {
   
    public:

        Reset_all_ButtonUI(Fl_Color color, int posx, int posy, int sizex, int sizey, int font_size, char new_texte[20], Controller* controller) : Clickable_ButtonUI{color, posx, posy, sizex, sizey, font_size, new_texte, controller}{}
        ~Reset_all_ButtonUI() = default;
        void mouseClick(Vector2D mouseLoc);

};

#endif
