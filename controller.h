
#ifndef _CONTROLLER_H
#define _CONTROLLER_H

// #include "sokoban.h"

class Controller
{   Sokoban *soko;
    public :
        Controller(Sokoban *soko): soko{soko}{};
        int process_key(int event)
        {
            tup position = soko->get_pos_player();

            switch(event)
            {
                case 'z':
                    position.y--;
                    if(soko->check_move(position, NORTH)){soko->play_move(position, NORTH);};
                    break;
                case 's':
                    position.y++;
                    if(soko->check_move(position, SOUTH)){soko->play_move(position, SOUTH);};
                    break;
                case 'q':
                    position.x--;
                    if(soko->check_move(position, WEST)){soko->play_move(position, WEST);};
                    break;
                case 'd':
                    position.x++;
                    if(soko->check_move(position, EAST)){soko->play_move(position, EAST);};
                    break;
                case 'r':
                    soko->reset_level();
                    break;
                case 'p':
                    printf("GAME OVER !!!\n");exit(0);
            }
        return 0;
    }
};

#endif