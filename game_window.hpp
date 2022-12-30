#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include "sokoban.hpp"
#include "controller.hpp"
#include "displayer.hpp"
#include <FL/Fl_Double_Window.H>
#include <bits/types/struct_timespec.h>
#include <ctime>
#include <iostream>

class Game_window : public Fl_Double_Window 
{   
    Controller controller;
    Displayer displayer;
    bool menu=true, game=false;
    int time=0;
    public:
        Game_window(Sokoban *soko) : Fl_Double_Window (100,100,650,550,"SOKOBAN MKovel + Kevin"), 
        controller{Controller(soko)}, 
        displayer{Displayer{soko}}
        {
            Fl::add_timeout(1.0/FREQ, Timer_CB, this);
        }   
        void draw() override //call FREQ/sec
        {   
            Fl_Window::draw();
            if(menu)
                cout<<"MENU"<<endl;
            {
                time++;
                displayer.draw_menu();
                if (time==2*FREQ)
                {
                    menu=false;
                    game=true;
                }
            } 
            if (game){
                displayer.draw();
                controller.listen_game();
            }
        }

        int handle(int event) override 
        {
            switch (event){

                case FL_KEYDOWN:
                    int event = Fl::event_key();
                    controller.process_key(event);
                    break;
                
                /*
                case FL_PUSH:
                    button.mouseClick(tup{Fl::event_x(), Fl::event_y()});
                    break; 
                */
                
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
