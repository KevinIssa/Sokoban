#ifndef _DISPLAYER_
#define _DISPLAYER_
#include "case.hpp"
#include "sokoban.hpp"
#include "buttons.hpp"
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
        char buffer[20]="";
        
        sprintf(buffer,"%d", soko->get_level());
        Button *lvl = new Button(FL_WHITE, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 50, buffer); 
        memset(buffer, 0, 20); 
        button_list.push_back(lvl);
        
        sprintf(buffer,"RESET");
        Button *reset_lvl = new Button(FL_YELLOW, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 35, buffer); 
        memset(buffer, 0, 20); 
        button_list.push_back(reset_lvl);

        sprintf(buffer,"QUIT");
        Button *quit = new Button(FL_GREEN, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 25, buffer); 
        button_list.push_back(quit);
        memset(buffer, 0, 20); 
        



        sprintf(buffer,"BEST = %d", soko->get_best_score());
        Button *best_score = new Button(FL_RED,  GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 3*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 15, buffer); 
        button_list.push_back(best_score);
        memset(buffer, 0, 20); 

        sprintf(buffer, "%d/%d", soko->get_used_step(), soko->get_limited_step());
        Button *score = new Button(FL_MAGENTA,  GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE, 25, buffer); 
        button_list.push_back(score);
        memset(buffer, 0, 20); 


        sprintf(buffer,"Change Level");
        Button *chg_lvl = new Button(FL_CYAN,  OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, buffer); 
        button_list.push_back(chg_lvl);
        memset(buffer, 0, 20); 

        sprintf(buffer,"");
        Button *reset_all = new Button(FL_CYAN,  OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, buffer); 
        button_list.push_back(reset_all);
        memset(buffer, 0, 20); 




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

