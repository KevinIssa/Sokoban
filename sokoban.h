#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
#include "case.h"
#include "player.h"
// #include "main_window.h"

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

// struct tup
// {
//     int x,y;
// };
// class Case;
class Sokoban 
{   private:
        int niveau =0 ;
        struct tup pos_player,original_pos,size_level;
        string level_s;
        vector<Case> original_level,level_c;
        vector <tup> goals_v;
        vector<string> data_level;
        // MainWindow window;
        // bool test = false;
        // bool allow_pushing=false;
        // char ch;
        // tup size_level;
        // vector<Case> level_c;

        void load_game();
        bool listen_key(tup &current_pos, int &push_dir, char ch);
        int print_game();

    public:
        void init();
        Sokoban();
        tup get_pos_player(){return pos_player;}
        void play();
        void play_move(tup &current_pos, int push_dir);
        bool check_move(tup &current_pos, int push_dir);
        void draw();
        void reset_level();
        vector<Case> get_level_c(){return level_c;};
        vector<Case> get_original_level_c(){return level_c;};
        int get_score();
        void listen_game();
        // void set_original_level(tup level){level_c = level}



};