#ifndef _CASE_H
#define _CASE_H

#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>

#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>


using namespace std;

struct tup
{
    int x,y;
};

class Case
{
    private:
        string name;
        char value; // for the algoritme
        char repr; //to draw
        tup position;
        Fl_Color color;
        Fl_Image *image;
        int size=50;

    public:
        Case(string name, char value,tup pos, Fl_Color col, Fl_Image *im): name{name},value{value},repr{value}, position{pos}, color{col}, image{im}{}
        // Case(string name, char value,tup pos, Fl_Color col): name{name},value{value},repr{value}, position{pos}, color{col}{}
        Case(string name, char value, char repr, tup pos, Fl_Color col, Fl_Image *im): name{name},value{value},repr{repr}, position{pos}, color{col},image{im}{}
        string get_name(){return name;}
        const char get_repr(){return repr;}
        const char get_value(){return value;}
        const char draw(){return repr;}
        void set_repr(char r){repr=r;}
        void set_value(char r){value=r;}
        tup get_pos(){return position;}
        void set_pos(tup pos){position=pos;}
        void set_pos(int y,int x){position = tup {x,y};}
        Fl_Color get_color(){return color;}
        int get_size(){return size;}
        Fl_Image * get_image(){return image;}
};

#endif