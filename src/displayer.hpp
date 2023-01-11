#ifndef _DISPLAYER_
#define _DISPLAYER_
#include "sokoban.hpp"
#include "buttonUI.hpp"
#include <FL/Fl_Image.H>
#include <vector>

const int FREQ=60;
const int GAME_SIZE = 500 ;
const int BOX_SIZE = GAME_SIZE / 10;
const int BEGIN_X = 0;
const int BEGIN_Y = 0;
const int OFFSET_BUTTON = 10;

using namespace std;
class Displayer 
{   
    private:
        Sokoban *soko;
        vector<ButtonUI> button_list;

        vector <Vector2D> player_pos; 
        vector <Vector2D> normal_goals;
        vector <Vector2D> purple_goals;
        vector <Vector2D> yellow_goals;
        vector <Vector2D> teleporter_cells;
        std::vector <Vector2D> box_list;
        vector <Vector2D> wall_list;

        vector< Fl_Image*> image_list;
    
    public:
        Displayer(Sokoban *soko) : soko{soko}{init_all();init_button();

        }
        ~Displayer()=default;
        void draw();
        /**
         * @brief: draw all images on board
         */

        void display_element(const char repr, vector <Vector2D> goal_list, Fl_Image* picture);
        
        void init_all();
        /**
         * @brief: initiate all images
         * 
         */

        void draw_menu();
        void draw_end_game();

        void create_button(Fl_Color color, int pos_x, int pos_y, int size_x, int size_y, int font_size, string txt);

        void draw_button();
        /**
         * @brief: check goals in goal_list and draw them
         *
         * @param repr: the representation of the goal in the board
         * @param goal_list: the vector of the type of goal
         * @param picture: the goal's .png
         */

        void init_button();
};

#endif
