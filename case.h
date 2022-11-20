#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>

//FLTK
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
        tup position;
        char repr; //to draw
        char value; // for the algoritme
        Fl_Color color;
        int size=50;
        // Fl_PNG_Image im {"Pok1.png"};
        // Fl_Image *im= Fl_PNG_Image {"Pok1.png"} .copy(size,size);
        Fl_Image *image;
        
        // Fl_JPEG_Image image ((const unsigned  char *)("Pok1.png"));
        // const uchar * image = (const unsigned  char *)("Pok1.png") ;

    public:
    // Case(string name, const char repr);
        Case(string name, char value,tup pos, Fl_Color col, Fl_Image *im): name{name},value{value},repr{value}, position{pos}, color{col}, image{im}{}
        // Case(string name, char value, char repr, tup pos, Fl_Color col,const char* im): name{name},value{value},repr{repr}, position{pos}, color{col}, image{im}{}
        Case(string name, char value,tup pos, Fl_Color col): name{name},value{value},repr{value}, position{pos}, color{col}{}
        Case(string name, char value, char repr, tup pos, Fl_Color col, Fl_Image *im): name{name},value{value},repr{repr}, position{pos}, color{col},image{im}{}
        // Case(const Case &o)
        // {
        //     name =o.name;
        //     position=o.position;
        //     repr = o.repr;
        //     value=o.value;
        //     color = o.color;
        //     // im = im.copy(50,50);
        // }
        string get_name(){return name;}
        const char get_repr(){return repr;}
        // void draw(){printf("%d",get_repr());}
        const char get_value(){return value;}
        const char draw(){return repr;}
        void set_repr(char r){repr=r;}
        void set_value(char r){value=r;}
        tup get_pos(){return position;}
        void set_pos(tup pos){position=pos;}
        void set_pos(int y,int x){position = tup {x,y};}
        Fl_Color get_color(){return color;}
        int get_size(){return size;}
        // const uchar * get_image(){return image;}
        Fl_Image * get_image(){return image;}

};