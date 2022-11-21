#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H


#include "sokoban.h"
#include "controller.h"
#include "display_game.h"


class MainWindow : public Fl_Window 
{   
    Controller controller;
    Display_game display;

    public:
        MainWindow(Sokoban *soko) : Fl_Window (100,100,650,550,"SOKOBAN MKovel + Idragus"), controller{Controller(soko)}, display{Display_game{soko}} 
        {
            Fl::add_timeout(1.0/FREQ, Timer_CB, this);
        }   
        void draw() override //call FREQ/sec
        {   
            Fl_Window::draw();
            display.draw();
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
            MainWindow *o = static_cast<MainWindow*>(userdata);
            o->redraw();
            Fl::repeat_timeout(1.0/FREQ, Timer_CB, userdata);
        }
};

#endif