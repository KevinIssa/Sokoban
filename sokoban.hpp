#ifndef _SOKOBAN_H
#define _SOKOBAN_H


#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
#include "case.hpp"
#include "player.hpp"
#include "level.hpp"

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

class Sokoban { 
      
private:

    unsigned int niveau =0 ;
    unsigned int limited_step;
    unsigned int used_step=0;
    unsigned int best_score;

    struct Vector2D pos_player,original_pos,size_level;
    string level_s;
    vector<Case> original_level,level_c;
    vector <Vector2D> goals_v;
    vector<string> data_level;

    void load_game();
    int print_game();

public:
    Sokoban();
    ~Sokoban()=default;
    void init();
    Vector2D get_pos_player(){return pos_player;}
    vector<Case> get_level_c(){return level_c;};
    vector<Case> get_original_level_c(){return level_c;};
    vector <Vector2D> get_goals_v(){return goals_v;};

    int get_goals_count();

    unsigned int get_level(){return niveau;}

    int get_limited_step(){
        return limited_step;
    }

    int get_used_step(){
        return used_step;
    }

    int get_best_score(){
        return best_score;
    }

    void set_limited_step(unsigned int step){
        limited_step=step;
    }

    vector<string> get_data_level(){return data_level;}

    int id(int x, int y);
    Vector2D reverse_id(int x);
    
    bool check_move(Vector2D &current_pos, int push_dir);
    void play_move(Vector2D &current_pos, int push_dir);
    void reset_level();
    void listen_game();
    void next_level();

    void draw();
    
};

#endif