#include "sokoban.h"

const int FREQ=120;

class MainWindow : public Fl_Window 
{     Sokoban soko;
    public:
        MainWindow() : Fl_Window (100,100,500,500,"SOKOBAN") 
        {
            // Sokoban soko;
            // soko.init();
            soko.init();
            // soko.play();
            soko.draw();
            // cout << "salu"<<endl;
            Fl::add_timeout(1.0/FREQ, Timer_CB, this);
            resizable(this);
        }   
        void draw() override //call FREQ/sec
        {   
            Fl_Window::draw();
            soko.listen_game();
            soko.draw();
        }

        int handle(int event) override 
        {
            switch (event) 
            {

                case FL_KEYDOWN:
                    tup position = soko.get_pos_player();

                    switch(Fl::event_key())
                    {
                        case 'z':
                            position.y--;
                            if(soko.check_move(position, NORTH)){soko.play_move(position, NORTH);};
                            break;
                        case 's':
                            position.y++;
                            if(soko.check_move(position, SOUTH)){soko.play_move(position, SOUTH);};
                            break;
                        case 'q':
                            position.x--;
                            if(soko.check_move(position, WEST)){soko.play_move(position, WEST);};
                            break;
                        case 'd':
                            position.x++;
                            if(soko.check_move(position, EAST)){soko.play_move(position, EAST);};
                            break;
                        case 'r':
                            soko.reset_level();
                            break;
                        case 'p':
                            printf("GAME OVER !!!\n");exit(0);
                }
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