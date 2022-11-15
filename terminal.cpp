// g++ -std=c++11 terminal.cpp -o term && ./term

#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
using namespace std;

int main()
{   
    const int NORTH = 0;
    const int EAST = 1;
    const int SOUTH = 2;
    const int WEST = 3;

    struct tup{
        int x,y;
    };

    string level_t = 
        "##########"
        "#        #"
        "#  $     #"
        "#      . #"
        "#  * $ $ #"
        "#    @   #"
        "#   +    #"  
        "#  ++    #"
        "# .      #"
        "##########";struct tup size_level_t= {10,10};

    string level =
        "##########"
        "##########"
        "#######  #"
        "###      #"
        "#     .  #"
        "# #  $ $ #"
        "#        #"
        "##### $$.#"
        "### @    #"
        "##########";struct tup size_level = {10,10};

    string level2 = 
        "##########"
        "#       ##"
        "# $    ###"
        "#. ## . ##"
        "# ####  ##"
        "#   #   ##"
        "#$$ #. ###"
        "# # # $@##"
        "# .    ###"
        "##########";


    string level3 = 
        "##########"
        "#.########"
        "#  #######"
        "# $  $@###"
        "# . . ####"
        "# # $$ . #"
        "# #    ###"
        "# ##### ##"
        "#        #"
        "##########";

    vector<string> data_level;
    data_level.push_back(level_t);
    data_level.push_back(level);
    data_level.push_back(level2);
    data_level.push_back(level3);
    int niveau =0 ;

    

    string level_s = data_level[niveau];
    size_level = size_level;

    struct tup pos_player;
    vector <tup> goals_v;
    auto id = [&](int x, int y) { return y * size_level.x + x; }; // fct type id

    for (int y=0;y<size_level.y;y++)
    {
        for (int x =0; x< size_level.x; x++)
        {
            switch (level_s[y * size_level.x + x])
            {
                case '@':
                    pos_player.x = x; 
                    pos_player.y = y;
                    break;
                case '.':
                    goals_v.push_back(tup{x,y});
                    level_s[id(x,y)]=' ';
                    break;
            }
        }
    }
    printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);for (auto &g:goals_v){if (level_s[id(g.x, g.y)]==' '){level_s[id(g.x, g.y)]='.';}}int i=0;string print_lvl="";for (auto &c:level_s){print_lvl+=c;i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='.' ){level_s[id(g.x, g.y)]=' ';}}int count =0;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='$'){count++;}}printf("%d / %lu\n", count, goals_v.size());
    bool win = true;
    tup original_pos = pos_player;
    char ch;
    cin >> ch;

    while(ch != 'p')
    {   
        tup current_pos = pos_player;
        int push_dir;
        bool test = false;
        bool allow_pushing=false;
        switch (ch)
        {
            case 'z':
                push_dir = NORTH;
                current_pos.y--;
                test = true;
                break;
            case 's':
                push_dir = SOUTH;
                current_pos.y++;
                test = true;
                break;
            case 'q':
                push_dir = WEST;
                current_pos.x--;
                test = true;
                break;
            case 'd':
                push_dir = EAST;
                current_pos.x++;
                test = true;
                break;  
            case 'r':
                level_s = data_level[niveau];
                pos_player.x=original_pos.x;
                pos_player.y=original_pos.y;
                break;
            case 'b':
                printf("YOU LOOSE !!\n");
                return 1;
        }
    return test;
}

bool check_move(bool& test, string &level_s, tup &current_pos, int push_dir)
{   
    bool allow_pushing=false;
        while(test)
        {
            if (level_s[id(current_pos.x, current_pos.y)] != '#')
            {
                if (level_s[id(current_pos.x, current_pos.y)] != ' ' &&  (level_s[id(current_pos.x, current_pos.y)] != '$'))
                {   
                    switch (push_dir)
                    {
                        case NORTH: current_pos.y--; break;
                        case SOUTH: current_pos.y++; break;
                        case EAST: current_pos.x++; break;
                        case WEST: current_pos.x--; break;
                    }
                }
                else if (level_s[id(current_pos.x, current_pos.y)] == '$')
                {  
                    switch(push_dir)
                    {
                        case NORTH: current_pos.y--; break;
                        case SOUTH: current_pos.y++; break;
                        case EAST: current_pos.x++; break;
                        case WEST: current_pos.x--; break;
                    }
                    if (level_s[id(current_pos.x, current_pos.y)] == ' ')
                    {
                        test = false;
                        allow_pushing = true;
                    }
                    else
                    {
                        test = false;
                        allow_pushing = false;
                    }
                }
                else
                { 
                    allow_pushing = true;
                    test=false;
                }
            }
            else
            {
                test=false;
            }
        }
        if (allow_pushing)
        { 
            while (current_pos.x != pos_player.x || current_pos.y != pos_player.y)
            {
                tup source = current_pos;
                switch (push_dir)
                {
                    case NORTH: source.y++; break;
                    case SOUTH: source.y--; break;
                    case EAST: source.x--; break;
                    case WEST: source.x++; break;
                }
                swap(level_s[id(source.x, source.y)], level_s[id(current_pos.x, current_pos.y)]);
                current_pos.x = source.x;
                current_pos.y = source.y;
            }
            switch (push_dir)
                {
                    case NORTH: pos_player.y--; break;
                    case SOUTH: pos_player.y++; break;
                    case EAST: pos_player.x++; break;
                    case WEST: pos_player.x--; break;
                }
        }
        // line for print 
        printf("\n");printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);for (auto &g:goals_v){if (level_s[id(g.x, g.y)]==' '){level_s[id(g.x, g.y)]='.';}}int i=0;string print_lvl="";for (auto &c:level_s){print_lvl+=c;i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='.' ){level_s[id(g.x, g.y)]=' ';}}int count =0;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='$' || level_s[id(g.x, g.y)]=='+'){count++;}}printf("%d / %lu\n", count, goals_v.size());
        
        if (count == goals_v.size())
        {
            niveau++;
            level_s = data_level[niveau];
            goals_v.clear();
            // count=0;
            for (int y=0;y<size_level.y;y++)
            {
                for (int x =0; x< size_level.x; x++)
                {
                    switch (level_s[y * size_level.x + x])
                    {
                        case '@':
                            pos_player.x = x; 
                            pos_player.y = y;
                            original_pos=pos_player;
                            break;
                        case '.':
                            goals_v.push_back(tup{x,y});
                            level_s[id(x,y)]=' ';
                            break;
                    }
                }
            }
    printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);for (auto &g:goals_v){if (level_s[id(g.x, g.y)]==' '){level_s[id(g.x, g.y)]='.';}}int i=0;string print_lvl="";for (auto &c:level_s){print_lvl+=c;i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='.' ){level_s[id(g.x, g.y)]=' ';}}int count =0;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='$'){count++;}}printf("%d / %lu\n", count, goals_v.size());

        }
        cin >> ch;
    }

    printf("YOU WIN !!\n"); 
    return 0;
}