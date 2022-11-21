
#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "sokoban.h"
class Controller
{   
    Sokoban *soko;
    public :
        Controller(Sokoban *soko): soko{soko}{};
        int process_key(int event);
        void listen_game();
};

#endif