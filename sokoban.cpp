#include "game_window.hpp"
#include "sokoban.hpp"

int Sokoban::id(int x, int y) //faire une fct lambda
{
    return y * 10 + x;
}

Vector2D Sokoban::reverse_id(int x)
{
    return Vector2D{x%10, x/10};
}

Sokoban::Sokoban()
        {   
            // init();
        }

void Sokoban::init()
{
    string level_t = 
        "##########"
        "#   # #  #"
        "#  $     #"
        "#      . #"
        "#    #   #"
        "#    @   #"
        "#        #"  
        "#        #"
        "# .$     #"
        "##########";
        // struct tup size_level_t= {10,10};

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
        "##########";struct Vector2D size_level_n = {10,10};

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
    load_game();
    
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
            Vector2D current ={x,y};
            switch (level_s[y * size_level.x + x])
            {
                case '@':
                {
                    Fl_Image *im =Fl_PNG_Image {"cap.png"} .copy(50,50);
                    Case player{"Player",level_s[y * size_level.x + x], current, FL_GREEN, im};
                    level_c.push_back(player);
                    pos_player = {x,y}; 
                    original_pos = pos_player;
                    break;
                }
                case '.':
                {   
                    Fl_Image *im =Fl_PNG_Image {"pika.png"} .copy(50,50);
                    Case obj{"Objective",' ',level_s[y * size_level.x + x], current, FL_WHITE, im};
                    level_c.push_back(obj);
                    goals_v.push_back(Vector2D{x,y});
                    break;
                }
                case '$':
                {   
                    Fl_Image *im =Fl_PNG_Image {"Pok1.png"} .copy(50,50);
                    Case box_h{"Heavy Box",level_s[y * size_level.x + x], current, FL_RED, im};
                    level_c.push_back(box_h);
                    break;
                }
                case '#':
                {   
                    Fl_Image *im =Fl_PNG_Image {"wall.png"} .copy(50,50);
                    Case wall{"Wall",level_s[y * size_level.x + x], current, FL_BLACK,im};
                    level_c.push_back(wall);
                    break;
                }
                case '+':
                {   
                    Fl_Image *im =Fl_PNG_Image {"wall.png"} .copy(50,50);
                    Case light_case{"Light Box",level_s[y * size_level.x + x], current, FL_CYAN,im};
                    level_c.push_back(light_case);
                    break;
                }
                default:
                {
                    Fl_Image *im =Fl_PNG_Image {"wall.png"} .copy(50,50);
                    Case free_case{"free",' ', current, FL_WHITE,im};
                    level_c.push_back(free_case);
                }   
            }
        }       
    }
for (auto&c:level_c){original_level.push_back(c);}

}

void Sokoban::play_move(Vector2D &current_pos, int push_dir)
{  
    while (current_pos.x != pos_player.x || current_pos.y != pos_player.y){
        Vector2D source = current_pos;
        switch (push_dir)
        {
            case NORTH: source.y++; break;
            case SOUTH: source.y--; break;
            case EAST: source.x--; break;
            case WEST: source.x++; break;
        }
        swap(level_c[id(source.x, source.y)], level_c[id(current_pos.x, current_pos.y)]);
        current_pos.x = source.x;
        current_pos.y = source.y;
    }

    switch (push_dir){
        case NORTH: pos_player.y--; break;
        case SOUTH: pos_player.y++; break;
        case EAST: pos_player.x++; break;
        case WEST: pos_player.x--; break;
    }
    used_step++;
    cout<<used_step<<endl;
}

int Sokoban::get_goals_count()
{
    int count=0;
    for (auto &goals:goals_v)
    {
        if (level_c[id(goals.x, goals.y)].get_repr()=='$'|| level_c[id(goals.x, goals.y)].get_repr()=='+')
        {
            count++;
        }
    }
    return count;
}
void Sokoban::listen_game()
{
    if (get_goals_count() == goals_v.size())
        {   
            printf("\nNice, you've succeeded lvl %d\n",niveau+1);
            niveau++;
            if (niveau==data_level.size()){printf("YOU WIN !!!\n"); exit(1);}
            printf("--> go to lvl %d\n",niveau+1);
            load_game();
            original_level.clear();
            for (auto &c:level_c){original_level.push_back(c);}
        }
}

bool Sokoban::check_move(Vector2D &current_pos, int push_dir)
{   
    int verif=0;
    bool allow_pushing=false;
    bool test=true;
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

void Sokoban::draw()
{   
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_WHITE);
    int i=0;
    for (auto &c:level_c)
    {
        if (c.get_value()!=' ' ){c.get_image()->draw(reverse_id(i).x*c.get_size(), reverse_id(i).y*c.get_size());}
        i++;
    }
    for (auto &goals:goals_v)
    {   
        if (level_c[id(goals.x, goals.y)].get_repr()=='.'||level_c[id(goals.x, goals.y)].get_repr()==' ')
        { 
           Fl_Image *im = Fl_PNG_Image{"pika.png"}.copy(40,40);
		   im->draw(goals.x*50,goals.y*50);
        }
    }
    
}

void Sokoban::reset_level()
{
    level_c.clear();
    for (auto&c:original_level)
    {
        level_c.push_back(c);
    }
    pos_player.x=original_pos.x;
    pos_player.y=original_pos.y;
    used_step=0;
}

void Sokoban::next_level()
{   niveau++;
    used_step=0;
    load_game();
    original_level.clear();
    for (auto &c:level_c){original_level.push_back(c);}
}



// int Sokoban::print_game()
// {
//     printf("\n");printf("SOKOBAN - GAME - level %d\n",niveau+1);
//     for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()==' '){level_c[id(g.x, g.y)].set_repr('.');}}
//     int i=0;string print_lvl="";for (auto &c:level_c){print_lvl+=c.draw();i++;if (i==size_level.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;
//     for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='.'){level_c[id(g.x, g.y)].set_repr(' ');}}
//     int count=0;for (auto &g:goals_v){if (level_c[id(g.x, g.y)].get_repr()=='$'|| level_c[id(g.x, g.y)].get_repr()=='+'){count++;}}printf("%d / %lu\n", count, goals_v.size());
//     fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_GRAY);
//     for (auto &c:level_c)
//     {
//         fl_draw_box(FL_FLAT_BOX, c.get_pos().x*c.get_size(), c.get_pos().y*c.get_size(), c.get_size(), c.get_size(), c.get_color());
//     }
//     return count;
// }  
