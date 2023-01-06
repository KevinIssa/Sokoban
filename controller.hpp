#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "sokoban.hpp"

const int UP_KEY = 65362;
const int DOWN_KEY = 65364;
const int LEFT_KEY = 65361;
const int RIGHT_KEY = 65363;

class Controller
{   

    Sokoban *soko;
    public :
        Controller(Sokoban *soko): soko{soko}{};
        ~Controller()=default;

        int process_key(int event);
        /**
         * @brief 
         * 
         */

        void listen_game();
        /**
         * @brief 
         * 
         */
};

#endif