#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include "sokoban.hpp"
#include "controller.hpp"
#include "displayer.hpp"
#include <FL/Enumerations.H>
#include <FL/Fl_Double_Window.H>
#include <ctime>
#include <iostream>

class Game_window : public Fl_Double_Window 
{   
    Displayer displayer;
    Controller controller;
    bool menu=true, game=false;
    int time=0;
    
    public:
        Game_window(Sokoban *soko) : Fl_Double_Window (100,100,650,550,"SOKOBAN MKovel + Kevin"), 
        displayer{Displayer{soko}}, 
        controller{Controller(soko, &displayer)}
        {
            Fl::add_timeout(1.0/FREQ, Timer_CB, this);
        }   
        void draw() override //call FREQ/sec
        {   
            Fl_Window::draw();
            if(menu){
                
                fl_font(FL_HELVETICA,60);
                fl_color(fl_rgb_color(0,0,255));
                fl_draw("MKOVEL + KEVIN",50,50,500,500,FL_ALIGN_CENTER,nullptr,false);


                time++;

                if (time==2*FREQ)//show the menu for 2 seconds
                {
                    menu=false;
                    game=true;
                }
            } 
            if (game){
                displayer.draw();
            }
        }

        int handle(int event) override 
        {
            switch (event){

                case FL_KEYDOWN:{
                    int event = Fl::event_key();
                    controller.process_key(event);
                    break;}
                
                case FL_PUSH:
                    controller.mouseClick(Vector2D{Fl::event_x(), Fl::event_y()});
                    return 1;
            }
            return 0;
        }
        static void Timer_CB(void *userdata) 
        {
            Game_window *o = static_cast<Game_window*>(userdata);
            o->redraw();
            Fl::repeat_timeout(1.0/FREQ, Timer_CB, userdata);
        }
};

#endif
