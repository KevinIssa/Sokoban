#include "sokoban.h"

int id(int x, int y) //faire une fct lambda
{
    return y * 10 + x;
}

Sokoban::Sokoban()
        {   
            init();
        }
void Sokoban::init()
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

void Sokoban::play()
{   
    // level_s = data_level[niveau];
    // int niveau =0 ;
    load_game();
    // load_game();

    // for (auto &g:goals_v){printf("\ngooooiX:%d,gogcgfgY:%d\n",g.x,g.y);}
    for (auto&c:level_c){original_level.push_back(c);}
    // printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);
    print_game();
    
    cin >> ch;
    while(ch!='`')
    {   
        tup current_pos = pos_player;
        int push_dir;
        bool test = listen_key(current_pos, push_dir);
        // if (listen_key(current_pos, push_dir))
        // {
        //     if (check_move(test, current_pos, push_dir))
        //     play_move(current_pos, push_dir);
        // }

        if (check_move(current_pos, push_dir))
            play_move(current_pos, push_dir);
            // play_move(current_pos, pos_player, push_dir, level_s, level_c);

        int count = print_game();

        if (count == goals_v.size())
        {   
            printf("\nNice, you've succeeded lvl %d\n",niveau+1);
            niveau++;
            if (niveau==data_level.size()){printf("YOU WIN !!!\n"); exit(1);}
            printf("--> go to lvl %d\n",niveau+1);
            load_game();

            original_level.clear();
            for (auto &c:level_c){original_level.push_back(c);}
            print_game();
            // level_s = data_level[niveau];
            // load_game( size_level, level_s, goals_v, original_pos, level_c);
            // load_game();

        
        }


        cin >> ch;
        if (feof(stdin) || ch == 'p')
        {   
            printf("GAME OVER !!!\n"); 
            exit(1);
        }
    }

}

void Sokoban::load_game()
    {
    goals_v.clear();
    level_c.clear();
    level_s = data_level[niveau];
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
                    pos_player = {x,y}; 
                    original_pos = pos_player;
                    break;
                }
                case '.':
                {   
                    Case obj{"Objective",' ',level_s[y * size_level.x + x]};
                    level_c.push_back(obj);
                    goals_v.push_back(tup{x,y});
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
                    Case light_case{"Light Box",level_s[y * size_level.x + x]};
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

void Sokoban::play_move(tup &current_pos, int push_dir)
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

int Sokoban::print_game()
{
    printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);
    for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()==' '){level_c[id(g.x, g.y)].set_repr('.');}}
    int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.draw();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;
    for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='.'){level_c[id(g.x, g.y)].set_repr(' ');}}
    int count=0;for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='$'|| level_c[id(g.x, g.y)].get_repr()=='+'){count++;}}printf("%d / %lu\n", count, goals_v.size());
    return count;
}  

bool Sokoban::listen_key(tup &current_pos, int &push_dir)
{
    test = false;
    allow_pushing=false;
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

bool Sokoban::check_move(tup &current_pos, int push_dir)
{   
    int verif=0;
    allow_pushing=false;
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

