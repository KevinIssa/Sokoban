#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "displayer.hpp"
#include "sokoban.hpp"
#include <FL/Enumerations.H>
#include <vector>
const int UP_KEY = 65362;
const int DOWN_KEY = 65364;
const int LEFT_KEY = 65361;
const int RIGHT_KEY = 65363;

class Controller
{   

    Sokoban *soko;
    Displayer *displayer;
    vector<Clickable_ButtonUI*> button_list; 

    public :
    Controller(Sokoban *soko, Displayer *displayer): soko{soko}, displayer{displayer}{button_init();
    };
        ~Controller()=default;

        int process_key(int event);
        /**
         * @brief : take the player's input, check it's validity and play it the move is valid
         */

        void mouseClick(Vector2D mouseLoc);
        void button_init();
        /**
         * @brief: construct all the buttons
         * 
         */

        void quit_game();
        void change_lvl(int offset_level);
        void reset_game();
        void reset_all_data();
        void listen_game();
        /**
         * @brief: check the state of the game, if the player succeded or failed the level, it notify him 
         * and get to the next level if he succeded
         * 
         */
};

#endif
