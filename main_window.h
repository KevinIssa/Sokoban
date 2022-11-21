#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H


#include "sokoban.h"
#include "controller.h"
#include "display_game.h"

// const int FREQ=60;

class MainWindow : public Fl_Window 
{   
    // Sokoban *soko;
    Controller controller;
    Display_game display;

    public:
        MainWindow(Sokoban *soko) : Fl_Window (100,100,650,550,"SOKOBAN MKovel + Idragus"), controller{Controller(soko)}, display{Display_game{soko}} 
        {


            // display = Display_game(soko);
            Fl::add_timeout(1.0/FREQ, Timer_CB, this);
            // Sokoban soko;
            // soko.init();
            // soko.init();
            // soko.play();
            // soko.draw();
            // cout << "salu"<<endl;
            // resizable(this);
        }   
        void draw() override //call FREQ/sec
        {   
            Fl_Window::draw();
            display.draw();
            controller.listen_game();
            // soko->draw();
        }

        int handle(int event) override 
        {
            switch (event) 
            {
                case FL_KEYDOWN:
                    int event = Fl::event_key();
                    controller.process_key(event);
                    break;

                //     tup position = soko->get_pos_player();

                //     switch(Fl::event_key())
                //     {
                //         case 'z':
                //             position.y--;
                //             if(soko->check_move(position, NORTH)){soko->play_move(position, NORTH);};
                //             break;
                //         case 's':
                //             position.y++;
                //             if(soko->check_move(position, SOUTH)){soko->play_move(position, SOUTH);};
                //             break;
                //         case 'q':
                //             position.x--;
                //             if(soko->check_move(position, WEST)){soko->play_move(position, WEST);};
                //             break;
                //         case 'd':
                //             position.x++;
                //             if(soko->check_move(position, EAST)){soko->play_move(position, EAST);};
                //             break;
                //         case 'r':
                //             soko->reset_level();
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