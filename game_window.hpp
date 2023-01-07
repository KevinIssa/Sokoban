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
            if(menu){
                
                time++;
                displayer.draw_menu();
                if (time==2*FREQ)//show the menu for 2 seconds
                {
                    menu=false;
                    game=true;
                }
            } 
            if (game){
                displayer.draw();
                displayer.draw_button();
                /* fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE , FL_RED); */
                /* fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE , FL_BLUE); */
                /* fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , FL_GREEN); */
                /* fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE , FL_WHITE); */
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
