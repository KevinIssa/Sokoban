// g++ -std=c++11 terminal.cpp -o term && ./term

#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

class Case
{
    private:
        string name;
        char repr;
        char value;


    public:
    // Case(string name, const char repr);
        Case(string name, char value): name{name},value{value},repr{value}{}
        Case(string name, char value, char repr): name{name},value{value},repr{repr}{}

        string get_name(){return name;}
        const char get_repr(){return repr;}
        // void draw(){printf("%d",get_repr());}
        const char get_value(){return value;}
        const char draw(){return repr;}
        void set_repr(char r){repr=r;}
        void set_value(char r){value=r;}




};

class Player : public Case
{
    public:
        Player(string name, char value): Case(name,value){}

};


struct tup
{
    int x,y;
};

int id(int x, int y) //faire une fct lambda
{
    return y * 10 + x;
}



void init(vector<string> &data_level, tup &size_level)
{
    string level_t = 
        "##########"
        "#        #"
        "#  $     #"
        "#    + . #"
        "#  * $ $ #"
        "#  ++@+  #"
        "#   +    #"  
        "#  ++    #"
        "# .$     #"
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
        "##########";struct tup size_level_n = {10,10};

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

    data_level.push_back(level_t);
    data_level.push_back(level);
    data_level.push_back(level2);
    data_level.push_back(level3);
    size_level = size_level_n;
}

void load_game(tup &pos_player, tup &size_level, string level_s, vector <tup> &goals_v, tup &original_pos, vector<Case> &level_c)
{
    goals_v.clear();
    level_c.clear();
    for (int y=0;y<size_level.y;y++)
    {
        for (int x =0; x< size_level.x; x++)
        {
            switch (level_s[y * size_level.x + x])
            {
                case '@':
                {
                    Player player{"Player",level_s[y * size_level.x + x]};
                    
                    level_c.push_back(player);
                    pos_player.x = x; 
                    pos_player.y = y;
                    original_pos = pos_player;
                    break;
                }
                case '.':
                {   
                    // Case obj{"Objective",level_s[y * size_level.x + x]};
                    Case obj{"Objective",level_s[y * size_level.x + x]},' '};
                    // Objective obj{"Objective",level_s[y * size_level.x + x]};
                    level_c.push_back(obj);
                    goals_v.push_back(tup{x,y});
                    level_s[id(x,y)]=' ';
                    break;
                }
                case '$':
                {
                    Case box_h{"Heavy Box",level_s[y * size_level.x + x]};
                    level_c.push_back(box_h);
                    break;
                }
                case '#':
                {
                    Case wall{"Wall",level_s[y * size_level.x + x]};
                    level_c.push_back(wall);
                    break;
                }
                case '+':
                {
                    Case light_case{"BLight Box",level_s[y * size_level.x + x]};
                    level_c.push_back(light_case);
                    break;
                }
                default:
                {
                    Case free_case{"free",' '};
                    level_c.push_back(free_case);
                }   
            }
        }   
    }
}

int print_game(vector<Case>&level_c, vector <tup>&goals_v, tup size_level)
{
    for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()==' '){printf("yoyy");level_c[id(g.x, g.y)].set_repr('.');}}
    int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.draw();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;
    for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='.'){level_c[id(g.x, g.y)].set_repr(' ');}}
    int count=0;for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='$'){count++;}}printf("%d / %lu\n", count, goals_v.size());
    return count;
}   

bool listen_key(tup &pos_player, char ch, tup &current_pos, int &push_dir, int niveau, string &level_s, vector<string> data_level, tup original_pos,vector<Case> &level_c, vector<Case> &original_level)
{
    printf("\npos_player =(%d,%d)\n",pos_player.x,pos_player.y);

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
        // level_s = data_level[niveau];
        level_c.clear();
        for (auto&c:original_level)
        {
            level_c.push_back(c);
        }
        // level_c = original_level;
        pos_player.x=original_pos.x;
        pos_player.y=original_pos.y;
        printf("RESET LVL ...");
        break;
    case 'p':
        printf("GAME OVER !!!\n");
        exit(1);
    }
    return test;
}

bool check_move(bool& test, string &level_s, tup &current_pos, int push_dir, vector<Case> &level_c)
{   
    int verif=0;
    bool allow_pushing=false;
    while(test)
    {
        switch (level_c[id(current_pos.x, current_pos.y)].get_value())
        {
        case '$':
            verif++;
            if(verif >1){test=false;break;} //stop condition to not stop pushing a heavy box
            switch (push_dir)
            {
                case NORTH: 
                    test = level_c[id(current_pos.x, current_pos.y--)].get_value() == ' ';
                    break;
                case SOUTH: 
                    test = level_c[id(current_pos.x, current_pos.y++)].get_value() == ' ';
                    break;
                case EAST: 
                    test = level_c[id(current_pos.x++, current_pos.y)].get_value() == ' ' ;
                    break;
                case WEST: 
                    test = level_c[id(current_pos.x--, current_pos.y)].get_value() == ' ' ;
                    break;
            }

            allow_pushing = level_c[id(current_pos.x, current_pos.y)].get_value() == ' ';
            test=false;
            break;
        case '#':
            test=false;
            break;
        case '+':
            verif++;
            switch (push_dir)
            {
                case NORTH: current_pos.y--; break;
                case SOUTH: current_pos.y++; break;
                case EAST: current_pos.x++; break;
                case WEST: current_pos.x--; break;
            }
            break;
        case ' ':
            allow_pushing = true;
            test=false;
            break;

        }
    }
    return allow_pushing;
}



            // if (level_c[id(current_pos.x, current_pos.y)].get_value() == ' ')
            // {
            //     test = false;
            //     allow_pushing = true;
            // }
            // else
            // {
            //     test=false;
            // }
    //             printf("\ncurrent pos=(%d,%d)\n",current_pos.x,current_pos.y);
    //     // if (level_s[id(current_pos.x, current_pos.y)] != '#')
    //     if (level_c[id(current_pos.x, current_pos.y)].get_value() != '#')
    //     {
    //         if (level_c[id(current_pos.x, current_pos.y)].get_value() != ' ' &&  (level_c[id(current_pos.x, current_pos.y)].get_value() != '$'))
    //         {   
    //             switch (push_dir)
    //             {
    //                 case NORTH: current_pos.y--; break;
    //                 case SOUTH: current_pos.y++; break;
    //                 case EAST: current_pos.x++; break;
    //                 case WEST: current_pos.x--; break;
    //             }
    //         }
    //         else if (level_c[id(current_pos.x, current_pos.y)].get_value() == '$')
    //         {  
    //             switch(push_dir)
    //             {
    //                 case NORTH: current_pos.y--; break;
    //                 case SOUTH: current_pos.y++; break;
    //                 case EAST: current_pos.x++; break;
    //                 case WEST: current_pos.x--; break;
    //             }
            
    //             if (level_c[id(current_pos.x, current_pos.y)].get_value() == ' ')
    //             {
    //                 test = false;
    //                 allow_pushing = true;
    //             }
    //             else
    //              printf("oui");
    //                 test = false; 
    //         }
    //         else
    //         { 
    //             allow_pushing = true;
    //             test=false;

    //         }
    //     }
    //     else
    //         test=false;
    //                 printf("non");


void play_move(tup &current_pos, tup &pos_player, int push_dir, string& level_s, vector<Case> &level_c)
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
        swap(level_c[id(source.x, source.y)], level_c[id(current_pos.x, current_pos.y)]);
        // swap(level_c[0], level_c[26]);
            // iter_swap(level_c.begin() + id(source.x, source.y), level_c.begin() + id(current_pos.x, current_pos.y));


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


void play(vector<string> data_level, tup size_level)
{   
    struct tup pos_player,original_pos;
    vector <tup> goals_v;
    vector<Case> level_c;
    char ch;
    int niveau =0 ;
    string level_s = data_level[niveau];
    load_game(pos_player, size_level, level_s, goals_v, original_pos, level_c);
    for (auto &g:goals_v){printf("\ngooooiX:%d,gogcgfgY:%d\n",g.x,g.y);}
    vector<Case> original_level;
    for (auto&c:level_c)
        {
            original_level.push_back(c);
        }

    printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);
    // for (auto &g:goals_v){if (level_s[id(g.x, g.y)]==' '){level_s[id(g.x, g.y)]='.';}}
    // for (auto &c:level_s){print_lvl+=c;i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}
    // cout <<print_lvl;
    // for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='.' ){level_s[id(g.x, g.y)]=' ';}}
    // int count =0;
    // for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='$'){count++;}}printf("%d / %lu\n", count, goals_v.size());





    // printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);for (auto &g:goals_v){if (level_s[id(g.x, g.y)]==' '){level_s[id(g.x, g.y)]='.';}}int i=0;string print_lvl="";for (auto &c:level_s){print_lvl+=c;i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='.' ){level_s[id(g.x, g.y)]=' ';}}int count =0;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='$'){count++;}}printf("%d / %lu\n", count, goals_v.size());
    
    // for (auto &g:goals_v){cout << g.x<<g.y<<endl;}
    // for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()==' '){level_c[id(g.x, g.y)].set_repr('.');}}
    // int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.draw();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;
    // for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='.'){level_c[id(g.x, g.y)].set_repr(' ');}}
    // int count=0;for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='$'){count++;}}printf("%d / %lu\n", count, goals_v.size());
    print_game(level_c,goals_v,size_level);
    
    cin >> ch;
    while(ch!='`')
    {   
        tup current_pos = pos_player;
        int push_dir;
        bool test = listen_key(pos_player, ch, current_pos, push_dir, niveau, level_s, data_level, original_pos,level_c, original_level);
        printf("\nbefore check: pos_player =(%d,%d)\n",pos_player.x,pos_player.y);

        if (check_move(test, level_s, current_pos, push_dir, level_c))
            play_move(current_pos, pos_player, push_dir, level_s, level_c);
        // printf("\n");printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);for (auto &g:goals_v){if (level_s[id(g.x, g.y)]==' '){level_s[id(g.x, g.y)]='.';}}int i=0; string print_lvl="";for (auto &c:level_s){print_lvl+=c;i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='.' ){level_s[id(g.x, g.y)]=' ';}} int count =0;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='$' || level_s[id(g.x, g.y)]=='+'){count++;}}printf("%d / %lu\n", count, goals_v.size());
        // int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.get_repr();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}
        // int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.draw();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;
        
        // for (auto &g:goals_v){cout << g.x<<g.y<<endl;}
        // for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()==' '){level_c[id(g.x, g.y)].set_repr('.');}}
        // int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.draw();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;
        // int count=0;for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='$'){count++;}}printf("%d / %lu\n", count, goals_v.size());
        // for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='.'){level_c[id(g.x, g.y)].set_repr(' ');}}
        int count = print_game(level_c, goals_v,size_level);

        if (count == goals_v.size())
        {   
            niveau++;
            printf("\nNice, you've succeeded lvl %d\n",niveau+1);
            if (niveau==data_level.size()){break;}
            printf("--> go to lvl %d\n",niveau+2);
            level_s = data_level[niveau];
            load_game(pos_player, size_level, level_s, goals_v, original_pos, level_c);
            original_level.clear();
            for (auto &c:level_c){original_level.push_back(c);}
            // printf("\n");printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);for (auto &g:goals_v){if (level_s[id(g.x, g.y)]==' '){level_s[id(g.x, g.y)]='.';}}int i=0; string print_lvl="";for (auto &c:level_s){print_lvl+=c;i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='.' ){level_s[id(g.x, g.y)]=' ';}} int count =0;for (auto &g:goals_v){if (level_s[id(g.x, g.y)]=='$' || level_s[id(g.x, g.y)]=='+'){count++;}}printf("%d / %lu\n", count, goals_v.size());
            // int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.draw();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}
            

            // for (auto &g:goals_v){cout << g.x<<g.y<<endl;}
            // for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()==' '){level_c[id(g.x, g.y)].set_repr('.');}}
            // int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.draw();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;
            // int count=0;for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='$'){count++;}}printf("%d / %lu\n", count, goals_v.size());
            // for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='.'){level_c[id(g.x, g.y)].set_repr(' ');}}
            print_game(level_c, goals_v,size_level);

        
        }


        cin >> ch;
        if (feof(stdin) || ch == 'p')
        {   
            printf("GAME OVER !!!\n"); 
            exit(1);
        }
    }
}

int main()
{   
    vector<string> data_level;
    // vector<Case> data_level;

    tup size_level;

    init(data_level, size_level);
    play(data_level, size_level);

    printf("YOU WIN !!\n"); 
    return 0;
}


