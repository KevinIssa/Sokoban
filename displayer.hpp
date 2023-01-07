#ifndef _DISPLAYER_
#define _DISPLAYER_
const int FREQ=60;
#include "sokoban.hpp"

class Displayer 
{   
    private:
        Sokoban *soko;
        vector <Vector2D> normal_goals;
        vector <Vector2D> purple_goals;
        vector <Vector2D> yellow_goals;
        vector <Vector2D> teleporter_cells;
        vector <Vector2D> box_list;
        const char * player_image="player.png";
        /* vector < <vector*> Vector2D > cells_game = {&normal_goals, &purple_goals, &yellow_goals, &yellow_goals, &teleporter_cells, &box_list }; */

        Vector2D player_pos; 
        /* vector <const char> representation = {".","/","*","&","$","H","M","+"}; */
        vector <char> representation = {'.','/','*','&','$','H','M','+'};
        vector<const char *>image= {"pika.png", "elekable.png", "giratina.png", "teleporter.png","pokeball.png", "hyper_ball.png","master_ball.png", "superball.png" };
        
        /* const char reprr [] = [ '.' , '/', '*', '&', '$','H','M','+']; */
        vector<Fl_Image> images_cells = {normal_goals_im, yellow_obj_im };
        /* Fl_Image[] image_cell = [normal_goals_im, yellow_obj_im  ]; */   
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
/* [ ] */

#endif

