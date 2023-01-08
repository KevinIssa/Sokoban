#ifndef _CASE_H
#define _CASE_H

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


using namespace std;

struct Vector2D
{
    int x,y;
};

class Case
{
    private:
        string name;
        char value; // for the algorithm
        char repr; //to draw
        Vector2D position;
        Fl_Color color;
        Fl_Image *image;
        int size=50;

    public:

        Case(char value,Vector2D pos, Fl_Color col): value{value},repr{value}, position{pos}, color{col}{}
        Case(char value, char repr, Vector2D pos, Fl_Color col): value{value},repr{repr}, position{pos}, color{col}{}
        string get_name(){return name;}
        char get_value(){return value;}
        char get_repr(){return repr;}
        Vector2D get_pos(){return position;}
        Fl_Color get_color(){return color;}
        Fl_Image * get_image(){return image;}
        int get_size(){return size;}

        void set_value(char r){value=r;}
        void set_repr(char r){repr=r;}
        void set_pos(int y,int x){position = Vector2D {x,y};}
};

#endif
