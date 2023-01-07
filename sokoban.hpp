#ifndef _SOKOBAN_H
#define _SOKOBAN_H


#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include "case.hpp"
#include "player.hpp"
#include "level.hpp"
#include <fstream>

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

const char PLAYER= '@';
const char WALL= '#';
const char TELEPORTER= '&';

const char NORMAL_OBJECTIVE= '.';
const char YELLOW_OBJECTIVE= '/';
const char PURPLE_OBJECTIVE= '*';

const char NORMAL_BOX= '$';
const char LIGHT_BOX= '+';
const char YELLOW_BOX= 'H';
const char PURPLE_BOX= 'M';

class Sokoban { 
      
private:
    int saved_line = 0;
    int level = 1 ;
    int used_step = 0;
    int best_score = 0, dimension_x =0 , dimension_y = 0, limited_step = 0;
    bool lost_flag = false;
    int next_tp = -1;

    vector<int> level_data={level, best_score, limited_step, dimension_x , dimension_y};
    struct Vector2D pos_player,original_pos,level_size;
    string level_s;

    vector<Case> original_level,level_cell;
   
    vector <Vector2D> wall_cell;
    vector <Vector2D> goals_cell;
    vector <Vector2D> normal_goals_cell;
    vector <Vector2D> yellow_goals_cell;
    vector <Vector2D> purple_goals_cell;
    vector <Vector2D> teleporter_cell;

    vector <Vector2D> box_list;
    vector<string> data_level;

    void load_game();
    /**
     * @brief browse all the board and create an object for each type of cell
     * 
     */

public:
    Sokoban() = default;
    ~Sokoban() = default;
    void init();
    //initiate the game
    
    Vector2D get_pos_player(){return pos_player;}
    vector<Case> get_level_cell(){return level_cell;};
    vector<Case> get_original_level_c(){return level_cell;};
    
    vector <Vector2D> get_teleporter_cell(){return teleporter_cell;}
    vector <Vector2D> get_wall_cell(){return wall_cell;}
    vector <Vector2D> get_goals_cell(){return goals_cell;}
    vector <Vector2D> get_yellow_goals(){return yellow_goals_cell;}
    vector <Vector2D> get_purple_goals(){return purple_goals_cell;}
    vector <Vector2D> get_normal_goals(){return normal_goals_cell;}
    vector <Vector2D> get_box_list(){return box_list;}

    int get_goals_count();
    /**
     * @brief: check for all types of boxes if they are on their respective goals
     * 
     * @return the number of box that are on their goals point
     */

    int get_level(){return level;}

    int get_limited_step(){
        return limited_step;
    }

    int get_used_step(){
        return used_step;
    }

    int get_best_score(){
        return best_score;
    }

    void set_limited_step(int step){
        limited_step=step;
    }

    //all the create methods create a new object of the specified entity
    void create_player(Vector2D current, int x, int y, Vector2D level_size);
    void create_normal_objective(Vector2D current, int x, int y, Vector2D level_size);
    void create_yellow_objective(Vector2D current, int x, int y, Vector2D level_size);
    void create_purple_objective(Vector2D current, int x, int y, Vector2D level_size);

    void create_normal_box(Vector2D current, int x, int y, Vector2D level_size);
    void create_light_box(Vector2D current, int x, int y, Vector2D level_size);
    void create_yellow_box(Vector2D current, int x, int y, Vector2D level_size);
    void create_purple_box(Vector2D current, int x, int y, Vector2D level_size);

    void create_wall(Vector2D current, int x, int y, Vector2D level_size);
    void create_teleporter(Vector2D current, int x, int y, Vector2D level_size);

    bool get_lost_flag(){ return lost_flag; }
    
    void read_data(ifstream& file ,  int& data);
    /**
     * @brief: take the digits for each line of information about the level and cast them into int 
     * and store them in the level_data
     */

    void read_data_level(ifstream& file , string& data);
    /**
     * @brief: read the string that represent the level and store it in a string
     * 
     * @param data: the string where the level will be stored
     */
    

    void read_level_file(int level_number);
    /**
     * @brief: read all the level information and treat them whith the function above
     * 
     * @param level_number: the actual level
     */

    void update_file(int new_best_score);
    /**
     * @brief: update the best score for the finished level 
     * 
     */

    vector<string> get_data_level(){return data_level;}

    // id gets the position of a cell in the board because the board is stored as a 1 dimension variable
    //instead of a 2 dimensions and;
    int id(int x, int y);

    //transform an id in x and y coordonates
    Vector2D reverse_id(int x);
    
    int can_tp(Vector2D & current_pos);
    /**
     * @brief: check if a teleporter is available to teleport the player
     * 
     * @return the place of the next teleporter in the board
     */
    int can_tp_end();

    void end_tp();
    
    bool check_move(Vector2D &current_pos, int push_dir);
    /**
     * @brief: check if a move is possible
     */

    bool safe_check_move(Vector2D current_pos, int push_dir);
    /**
     * @brief: does the same as check_move but without impacting the current_pos  
     */

    void fill_box_list();
    /**
     * @brief: browse the board to store the boxes in the box list vector
     */

    bool are_box_blocked();
    /**
     * @brief: check if all boxes are blocked
     */

    int is_lost();
    /**
     * @brief: check if one of the losing condition is valided (limited stop or are_box_blocked)
     * 
     */

    void play_move(Vector2D &current_pos, int push_dir);
    /**
     * @brief: play the move on the board after check move validated it
     * 
     */

    void clear_vectors();
    /**
     * @brief: clear all vectors after a level is completed
     * 
     */

    void reset_level();
    /**
     * @brief: if the player press r the level is reset
     * 
     */

    void next_level();
    /**
     * @brief: load the next level and update the best score
     * 
     */
        
};

#endif
   
