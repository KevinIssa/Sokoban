#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H

#include "sokoban.h"
#include "display_game.h"
#include "controller.h"

#include <FL/Fl_Button.H>

// const int FREQ=60;

class MainWindow : public Fl_Window //Controler
{   Sokoban *soko; //Model
    Display_game display;
    Controller controller;
    // Fl_Window *win;
    // Fl_Button *reset;
    public:
        MainWindow(Sokoban *soko) : Fl_Window (100,100,650,550,"SOKOBAN MKovel + Idragus"), soko{soko}, display{Display_game{soko}}, controller{Controller{soko}}
        {   
            Fl::add_timeout(1.0/FREQ, Timer_CB, this);
            resizable(this);
            // soko.init();
            // soko=soko;
            // display = new Display_game(soko);
            // contrController{soko};

            // win = new Fl_Window (500,0,150,550,"tot");
            // win->begin();
            // reset = new Fl_Button(80/2, 10, 80, 25, "Beep");
            // win->end();

            // this->begin();
            // reset = new Fl_Button(500 + 80/2, 10, 80, 25, "RESET");
            // this->end();

            // Fl_Button *b1 = new Fl_Button(20, 10, 80, 25, "Beep");
            // Sokoban soko;
            // soko.init();


            // soko.init();


            // soko.play();
            // soko.draw();
            // cout << "salu"<<endl;
            // Fl_Button *b1 = new Fl_Button(700, 10, 80, 25, "Beep");
        }   
        void draw() override //call FREQ/sec
        {   
            // Fl_Window::draw();
            display.draw();

            // soko->listen_game();
            // soko->draw();
        }

        int handle(int event) override 
        {
            switch (event) 
            {

                case FL_KEYDOWN:

                    int event = Fl::event_key();
                    controller.process_key(event);






                //     tup position = soko.get_pos_player();

                //     switch(Fl::event_key())
                //     {
                //         case 'z':
                //             position.y--;
                //             if(soko.check_move(position, NORTH)){soko.play_move(position, NORTH);};
                //             break;
                //         case 's':
                //             position.y++;
                //             if(soko.check_move(position, SOUTH)){soko.play_move(position, SOUTH);};
                //             break;
                //         case 'q':
                //             position.x--;
                //             if(soko.check_move(position, WEST)){soko.play_move(position, WEST);};
                //             break;
                //         case 'd':
                //             position.x++;
                //             if(soko.check_move(position, EAST)){soko.play_move(position, EAST);};
                //             break;
                //         case 'r':
                //             soko.reset_level();
                //             break;
                //         case 'p':
                //             printf("GAME OVER !!!\n");exit(0);
                // }
            
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