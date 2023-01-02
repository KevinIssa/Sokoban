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

const char player= '@';
const char wall= '#';
const char teleporter= '&';

const char normal_objective= '.';
const char yellow_objective= '/';
const char purple_objective= '*';

const char normal_box= '$';
const char light_box= '+';
const char yellow_box= 'H';
const char purple_box= 'M';

class Sokoban { 
      
private:
    int saved_line = 0;
    int level = 1 ;
    int used_step = 0;
    int best_score = 0, dimension_x =0 , dimension_y = 0, limited_step = 0;
    bool lost_flag = false;

    vector<int> level_data={level, best_score, limited_step, dimension_x , dimension_y};
    struct Vector2D pos_player,original_pos,level_size;
    string level_s;

    vector<Case> original_level,level_cell;
    
    vector <Vector2D> goals_cell;
    vector <Vector2D> normal_goals_cell;
    vector <Vector2D> yellow_goals_cell;
    vector <Vector2D> purple_goals_cell;
    vector <Vector2D> teleporter_cell;

    vector <Vector2D> box_list;
    vector<string> data_level;

    void load_game();
    int print_game();

public:
    Sokoban() = default;
    ~Sokoban() = default;
    void init();
    
    Vector2D get_pos_player(){return pos_player;}
    vector<Case> get_level_cell(){return level_cell;};
    vector<Case> get_original_level_c(){return level_cell;};

    vector <Vector2D> get_goals_cell(){return goals_cell;}
    vector <Vector2D> get_box_list(){return box_list;}

    int get_goals_count();

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

    void read_level_file(int level_number);

    void read_data(ifstream& file ,  int& data);
    void read_data_level(ifstream& file , string& data);
    
    vector<string> get_data_level(){return data_level;}

    int id(int x, int y);
    Vector2D reverse_id(int x);
    
    bool can_tp(); 
    bool check_move(Vector2D &current_pos, int push_dir);

    bool safe_check_move(Vector2D current_pos, int push_dir);
    bool are_box_blocked();
    bool is_lost();
    void play_move(Vector2D &current_pos, int push_dir);

    void reset_level();
    void listen_game();
    void next_level();

    void update_file(int new_best_score);
    void draw();
    
};

#endif
