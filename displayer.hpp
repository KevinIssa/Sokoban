#ifndef _DISPLAYER_
#define _DISPLAYER_
#include "case.hpp"
#include "sokoban.hpp"
#include "button.hpp"
#include <vector>

const int FREQ=60;
const int GAME_SIZE = 500 ;
const int BOX_SIZE = GAME_SIZE / 10;
const int BEGIN_X = 0;
const int BEGIN_Y = 0;
const int OFFSET_BUTTON = 10;


class Displayer 
{   
    private:
        Sokoban *soko;
        vector<Button*> button_list;

        vector <Vector2D> normal_goals;
        vector <Vector2D> purple_goals;
        vector <Vector2D> yellow_goals;
        vector <Vector2D> teleporter_cells;
        vector <Vector2D> box_list;
        vector <Vector2D> wall_list;
        /* Case *current_case; */

        Fl_Image * player_img = Fl_PNG_Image {"player.png"} .copy(BOX_SIZE,BOX_SIZE);
        Fl_Image * normal_goals_img = Fl_PNG_Image {"pika.png"} .copy(BOX_SIZE,BOX_SIZE);
        Fl_Image * yellow_goals_img = Fl_PNG_Image {"elekable.png"} .copy(BOX_SIZE,BOX_SIZE);
        Fl_Image * purple_goals_img = Fl_PNG_Image {"giratina.png"} .copy(BOX_SIZE,BOX_SIZE);
        Fl_Image * teleporter_cells_img = Fl_PNG_Image {"teleporter.png"} .copy(BOX_SIZE,BOX_SIZE);
        
        Fl_Image * normal_box_img = Fl_PNG_Image {"pokeball.png"} .copy(BOX_SIZE,BOX_SIZE);
        Fl_Image * light_box_img = Fl_PNG_Image {"hyper_ball.png"} .copy(BOX_SIZE,BOX_SIZE);
        Fl_Image * purple_box_img = Fl_PNG_Image {"master_ball.png"} .copy(BOX_SIZE,BOX_SIZE);
        Fl_Image * yellow_box_img = Fl_PNG_Image {"superball.png"} .copy(BOX_SIZE,BOX_SIZE);
        Fl_Image * wall_img = Fl_PNG_Image {"grey_wall.png"} .copy(BOX_SIZE,BOX_SIZE);
        Vector2D player_pos; 

    public:
        Displayer(Sokoban *soko) : soko{soko}{
        

        }
        ~Displayer()=default;
        void draw(); // cal FREQ/seq
        void display_element(const char repr, vector <Vector2D> goal_list, Fl_Image* picture);
        void draw_button();
        /**
         * @brief: check goals in goal_list and draw them
         *
         * @param repr: the representation of the goal in the board
         * @param goal_list: the vector of the type of goal
         * @param picture: the goal's .png
         */

        void draw_menu();
        void draw_end_game();

};
/* [ ] */

#endif

