
#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "sokoban.hpp"
class Controller
{   
    Sokoban *soko;
    public :
        Controller(Sokoban *soko): soko{soko}{};
        ~Controller()=default;
        int process_key(int event);
        void listen_game();
};

#endif