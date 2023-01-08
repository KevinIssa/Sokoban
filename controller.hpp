#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "case.hpp"
#include "displayer.hpp"
#include "sokoban.hpp"
/* #include "buttons.hpp" */
/* #include "displayer.hpp" */
#include <FL/Enumerations.H>
#include <vector>
const int UP_KEY = 65362;
const int DOWN_KEY = 65364;
const int LEFT_KEY = 65361;
const int RIGHT_KEY = 65363;

class Controller
{   

    Sokoban *soko;
    vector<Clickable_ButtonUI*> button_list; 
    /* bool menu, quit, reset_level, reset_all_data, chg_level; */
    public :
    Controller(Sokoban *soko): soko{soko}{init();
        /* char buffer[20]=""; */
        
        /* sprintf(buffer,"%d", soko->get_level()); */
        /* Button *lvl = new Button(FL_WHITE, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 50, buffer); */ 
        /* memset(buffer, 0, 20); */ 
        /* button_list.push_back(lvl); */
        
        /* sprintf(buffer,"RESET"); */
        /* Button *reset_lvl = new Button(FL_YELLOW, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 35, buffer); */ 
        /* memset(buffer, 0, 20); */ 
        /* button_list.push_back(reset_lvl); */

        /* sprintf(buffer,"QUIT"); */
        /* Button *quit = new Button(FL_GREEN, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 25, buffer); */ 
        /* button_list.push_back(quit); */
        /* memset(buffer, 0, 20); */ 
        


        /* sprintf(buffer,"BEST = %d", soko->get_best_score()); */

        /* Button *best_score = new Button(FL_RED,  GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 3*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 15, buffer); */ 
        /* button_list.push_back(best_score); */
        /* memset(buffer, 0, 20); */ 

        /* sprintf(buffer, "%d/%d", soko->get_used_step(), soko->get_limited_step()); */
        /* Button *score = new Button(FL_MAGENTA,  GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE, 25, buffer); */ 
        /* button_list.push_back(score); */
        /* memset(buffer, 0, 20); */ 


        /* sprintf(buffer,"Change Level"); */
        /* Button *chg_lvl = new Button(FL_CYAN,  OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, buffer); */ 
        /* button_list.push_back(chg_lvl); */
        /* memset(buffer, 0, 20); */ 

        /* sprintf(buffer,""); */
        /* Button *reset_all = new Button(FL_CYAN,  OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, buffer); */ 
        /* button_list.push_back(reset_all); */
        /* memset(buffer, 0, 20); */ 





    };
        ~Controller()=default;

        int process_key(int event);
        /**
         * @brief : take the player's input, check it's validity and play it the move is valid
         */

        void mouseClick(Vector2D mouseLoc);
        void init();
        void quit_game() ;
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
