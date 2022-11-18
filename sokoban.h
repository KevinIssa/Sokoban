
#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
#include "case.h"
#include "player.h"

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

struct tup
{
    int x,y;
};

class Sokoban 
{   private:
        int niveau =0 ;
        char ch;
        vector<Case> original_level;
        tup size_level;
        struct tup pos_player,original_pos;
        vector<Case> level_c;
        string level_s;
        vector <tup> goals_v;
        vector<string> data_level;
        bool test = false;
        bool allow_pushing=false;
        void init();
        void load_game();
        bool listen_key(tup &current_pos, int &push_dir);
        bool check_move(tup &current_pos, int push_dir);
        void play_move(tup &current_pos, int push_dir);
        int print_game();

    public:
        Sokoban();
        void play();


};