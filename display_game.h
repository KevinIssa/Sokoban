#ifndef _DISPLAY_GAME_
#define _DISPLAY_GAME_

// #include "main_window.h"

const int FREQ=60;

class Display_game 
{   
    // sokoban *soko;
    // MainWindow window;
    private:
        Sokoban *soko;
        int id(int x, int y){return y * 10 + x;}
        tup reverse_id(int x){return tup{x%10, x/10};}
    public:
        Display_game(Sokoban *soko) : soko{soko}{}
        void draw() //override // cal FREQ/seq
        {   
            // soko->listen_game();
            fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_WHITE);
            int i=0;
            for (auto &c:soko->get_level_c())
            {
                if (c.get_value()!=' ' ){c.get_image()->draw(reverse_id(i).x*c.get_size(), reverse_id(i).y*c.get_size());}
                i++;
            }
            for (auto &g:soko->get_goals_v())
            {   
                if (soko->get_level_c()[id(g.x, g.y)].get_repr()=='.'||soko->get_level_c()[id(g.x, g.y)].get_repr()==' ')
                {  
                    
                    Fl_Image *im =Fl_PNG_Image {"pika.png"} .copy(50,50);
                    im->draw(g.x*50, g.y*50);
                }
            }

        }
};


#endif




        // static void Timer_CB(void *userdata) 
        // {
        //     Display_game *o = static_cast<Display_game*>(userdata);
        //     o->redraw();
        //     Fl::repeat_timeout(1.0/FREQ, Timer_CB, userdata);
        // }
                    // fl_draw_image(const uchar *buf,reverse_id(i).x*c.get_size(), reverse_id(i).y*c.get_size(), c.get_size(), c.get_size(),int D,int L)
                    // cout<<"condition"<<endl;
                    // level_c[id(g.x, g.y)].set_repr('.');
                    // fl_draw_box(FL_FLAT_BOX, g.x*50, g.y*50,50, 50, FL_YELLOW) ;
                // cout<<g.x<<" , "<<g.y<< level_c[id(g.x, g.y)].get_repr()<<endl;
            // cout<<"t"<<endl;
            // cout<<"draw"<<endl;
                // fl_draw_image(c.get_image(),reverse_id(i).x*c.get_size(), reverse_id(i).y*c.get_size(), c.get_size(), c.get_size()+1);
                // if (c.get_value()!='#') fl_draw_box(FL_FLAT_BOX, reverse_id(i).x*c.get_size(), reverse_id(i).y*c.get_size(), c.get_size(), c.get_size(), c.get_color());
            // Fl_Window::draw();

        // {   
            
        //     Fl::add_timeout(1.0/FREQ, Timer_CB, this);
        //     resizable(this);
        // }





        // int handle(int event) override 
        // {
        //     switch (event) 
        //     {

        //         case FL_KEYDOWN:
        //             tup position = soko->get_pos_player();

        //             switch(Fl::event_key())
        //             {
        //                 case 'z':
        //                     position.y--;
        //                     if(soko->check_move(position, NORTH)){soko->play_move(position, NORTH);};
        //                     break;
        //                 case 's':
        //                     position.y++;
        //                     if(soko->check_move(position, SOUTH)){soko->play_move(position, SOUTH);};
        //                     break;
        //                 case 'q':
        //                     position.x--;
        //                     if(soko->check_move(position, WEST)){soko->play_move(position, WEST);};
        //                     break;
        //                 case 'd':
        //                     position.x++;
        //                     if(soko->check_move(position, EAST)){soko->play_move(position, EAST);};
        //                     break;
        //                 case 'r':
        //                     soko->reset_level();
        //                     break;
        //                 case 'p':
        //                     printf("GAME OVER !!!\n");exit(0);
        //         }
        //     }
        //     return 0;
        // }









