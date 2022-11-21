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

class Sokoban 
{   private:
        int niveau =0 ;
        struct tup pos_player,original_pos,size_level;
        string level_s;
        vector<Case> original_level,level_c;
        vector <tup> goals_v;
        vector<string> data_level;

        void load_game();
        int print_game();

    public:
        Sokoban();
        void init();
        tup get_pos_player(){return pos_player;}
        vector<Case> get_level_c(){return level_c;};
        vector<Case> get_original_level_c(){return level_c;};
        vector <tup> get_goals_v(){return goals_v;};
        int get_score();
        int get_level(){return niveau;}
        vector<string> get_data_level(){return data_level;}

        int id(int x, int y);
        tup reverse_id(int x);
        
        bool check_move(tup &current_pos, int push_dir);
        void play_move(tup &current_pos, int push_dir);
        void reset_level();
        void listen_game();
        void next_level();

        void draw();
        
};

#endif