#ifndef _DISPLAYER_
#define _DISPLAYER_
const int FREQ=60;
#include "sokoban.hpp"

class Displayer 
{   
    private:
        Sokoban *soko;
       
    public:
        Displayer(Sokoban *soko) : soko{soko}{}
        ~Displayer()=default;
        void draw(); // cal FREQ/seq

        void display_goals(const char repr, vector <Vector2D> goal_list, const char* picture);
        /**
         * @brief: check goals in goal_list and draw them
         *
         * @param repr: the representation of the goal in the board
         * @param goal_list: the vector of the type of goal
         * @param picture: the goal's .png
         */

        void draw_menu();

};


#endif

