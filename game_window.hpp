#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H


#include "sokoban.hpp"
#include "controller.hpp"
#include "displayer.hpp"


class Game_window : public Fl_Window 
{   
    Controller controller;
    Displayer displayer;

    public:
        Game_window(Sokoban *soko) : Fl_Window (100,100,650,550,"SOKOBAN MKovel + Idragus"), controller{Controller(soko)}, displayer{Displayer{soko}} 
        {
            Fl::add_timeout(1.0/FREQ, Timer_CB, this);
        }   
        void draw() override //call FREQ/sec
        {   
            Fl_Window::draw();
            displayer.draw();
            controller.listen_game();
        }

        int handle(int event) override 
        {
            switch (event) 
            {
                case FL_KEYDOWN:
                    int event = Fl::event_key();
                    controller.process_key(event);
                    break;
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