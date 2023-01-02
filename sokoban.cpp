#include "sokoban.hpp"
#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <type_traits>

int Sokoban::id(int x, int y) //faire une fct lambda
{
    return y * 10 + x;
}

Vector2D Sokoban::reverse_id(int x)
{
    return Vector2D{x%10, x/10};
}

void Sokoban::init(){   
    
    load_game();
    
}

void Sokoban::read_data(ifstream& file , int& data){
    string str_line;
    getline(file , str_line);
    string buffer;
    
    buffer=str_line.substr(str_line.size() - 3);
    /* cout<<"buffer= "<<buffer<<endl; */
    data = stoi(buffer);
}

void Sokoban::read_data_level(ifstream& file , string& data){

    unsigned int offset = level_data[3];
    string void_line, str_line;
    level_s.clear();

    getline(file , void_line);
    for (int i = 0 ; i<offset; i++){
        getline(file, str_line);
        level_s += str_line;
    }
}
void Sokoban::read_level_file(int level_number){

    ifstream level_file("levels.txt");
    string void_line;
    
    for (int i=1;i<=saved_line;i++){

        getline(level_file, void_line);
    }
   
    for(int i = 0; i<level_data.size(); i++){

        read_data(level_file , level_data[i]);
        saved_line++;
    }

    read_data_level(level_file, level_s);
    saved_line += level_data[4];
    saved_line += 3;
    level_file.close();
}

void Sokoban::update_file(int new_best_score){

    string line;
    ofstream out("tmp.txt");
    ifstream in("levels.txt");
    
    char new_line [100];
    snprintf(new_line, sizeof("best_score = %03d\n"), "best_score = %03d\n", new_best_score);
    int current_line=0;

    while(getline(in, line)){
        current_line++;
        if (line[0]=='b' && current_line < saved_line && current_line > saved_line - (8+level_data[4]) ){
            out<<new_line;
        }
        else{
            out<<line<<endl;
        }
    }

    in.close();out.close();
    rename("tmp.txt","levels.txt");
    remove("tmp.txt");
}

void Sokoban::create_player(Vector2D current, int x, int y, Vector2D level_size){

    Fl_Image *im =Fl_PNG_Image {"player.png"} .copy(50,50);
    Case player{"Player",level_s[y * level_size.x + x], current, FL_GREEN, im};
    level_cell.push_back(player);
    pos_player = {x,y}; 
    original_pos = pos_player;
}

void Sokoban::create_normal_objective(Vector2D current, int x, int y, Vector2D size_level){

    Fl_Image *im =Fl_PNG_Image {"pika.png"} .copy(50,50);
    Case obj{"Objective",' ',level_s[y * level_size.x + x], current, FL_WHITE, im};
    level_cell.push_back(obj);
    normal_goals_cell.push_back(Vector2D{x,y});
    goals_cell.push_back(Vector2D{x,y});
}

void Sokoban::create_yellow_objective(Vector2D current, int x, int y, Vector2D size_level){

    Fl_Image *im =Fl_PNG_Image {"elekable.png"} .copy(50,50);
    Case yellow_obj{"Yellow Objective",' ',level_s[y * level_size.x + x], current, FL_WHITE, im};
    level_cell.push_back(yellow_obj);
    yellow_goals_cell.push_back(Vector2D{x,y});
    goals_cell.push_back(Vector2D{x,y});
}

void Sokoban::create_purple_objective(Vector2D current, int x, int y, Vector2D size_level){

    Fl_Image *im =Fl_PNG_Image {"giratina.png"} .copy(50,50);
    Case purple_obj{"Purple Objective",' ',level_s[y * level_size.x + x], current, FL_WHITE, im};
    level_cell.push_back(purple_obj);
    purple_goals_cell.push_back(Vector2D{x,y});
    goals_cell.push_back(Vector2D{x,y});
}

void Sokoban::create_normal_box(Vector2D current, int x, int y, Vector2D size_level){

    Fl_Image *im =Fl_PNG_Image {"pokeball.png"} .copy(50,50);
    Case box_h{"Heavy Box",level_s[y * level_size.x + x], current, FL_RED, im};
    level_cell.push_back(box_h);
    box_list.push_back(Vector2D{x,y});
}

void Sokoban::create_light_box(Vector2D current, int x, int y, Vector2D size_level){

    Fl_Image *im =Fl_PNG_Image {"superball.png"} .copy(50,50);
    Case light_case{"Light Box",level_s[y * level_size.x + x], current, FL_CYAN,im};
    level_cell.push_back(light_case);
    box_list.push_back(Vector2D{x,y});
}

void Sokoban::create_yellow_box(Vector2D current, int x, int y, Vector2D size_level){

    Fl_Image *im =Fl_PNG_Image {"hyper_ball.png"} .copy(50,50);
    Case hyper_ball{"Hyper ball",level_s[y * level_size.x + x], current, FL_CYAN,im};
    level_cell.push_back(hyper_ball);
    box_list.push_back(Vector2D{x,y});
}

void Sokoban::create_purple_box(Vector2D current, int x, int y, Vector2D size_level){

    Fl_Image *im =Fl_PNG_Image {"master_ball.png"} .copy(50,50);
    Case master_ball{"Master ball",level_s[y * level_size.x + x], current, FL_CYAN,im};
    level_cell.push_back(master_ball);
    box_list.push_back(Vector2D{x,y});
}

void Sokoban::create_wall(Vector2D current, int x, int y, Vector2D size_level){

    Fl_Image *im =Fl_PNG_Image {"grey_wall.png"} .copy(50,50);
    Case wall{"Wall",level_s[y * level_size.x + x], current, FL_BLACK,im};
    level_cell.push_back(wall);
}

void Sokoban::create_teleporter(Vector2D current, int x, int y, Vector2D size_level){
    Fl_Image *im =Fl_PNG_Image {"teleporter.png"} .copy(50,50);
    Case teleporter{"teleporter",level_s[y * level_size.x + x], current, FL_BLACK,im};
    level_cell.push_back(teleporter);
}
void Sokoban::load_game(){

    goals_cell.clear();
    level_cell.clear();
    //level_s = data_level[level];
    read_level_file(level);
    level_size={level_data[3] ,level_data[4]};

    for (int y=0;y<level_size.y; y++)
    {
        for (int x =0; x< level_size.x; x++)
        {
            Vector2D current ={x,y};
            switch (level_s[y * level_size.x + x])
            {
                case player:{
                    create_player(current, x, y, level_size);
                    break;
                }

                case normal_objective:{   
                    create_normal_objective(current, x , y ,level_size);
                    break;
                }

                case yellow_objective:{
                    create_yellow_objective(current, x , y, level_size);
                    break;
                }

                case purple_objective:{
                    create_purple_objective(current, x , y , level_size);
                    break;
                }

                case normal_box:{   
                    create_normal_box(current, x , y ,level_size);
                    break;
                }

                case wall:{   
                    create_wall(current , x, y , level_size);
                    break;
                }
                case teleporter:{
                    create_teleporter(current , x, y , level_size);
                    break;
                }
                
                case light_box:{   
                    create_light_box(current, x , y , level_size);
                    break;
                }

                case yellow_box:{
                    create_yellow_box(current, x , y ,level_size);
                    break;
                }

                case purple_box:{
                    create_purple_box(current, x , y , level_size);
                    break;
                }

                default:
                {
                    Fl_Image *im =Fl_PNG_Image {"grey_wall.png"} .copy(50,50);
                    Case free_case{"free",' ', current, FL_WHITE,im};
                    level_cell.push_back(free_case);
                }   
            }
        }       
    }

for (auto&c:level_cell){original_level.push_back(c);}

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
        swap(level_cell[id(source.x, source.y)], level_cell[id(current_pos.x, current_pos.y)]);
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
    cout<<"used step: "<<used_step<<endl;
    if (are_box_blocked()){
        cout<<"BLOKééééééé"<<endl;
    }
}

int Sokoban::get_goals_count(){

    int count=0;
    for (auto &goals:normal_goals_cell)
    {
        if (level_cell[id(goals.x, goals.y)].get_repr()=='$'|| level_cell[id(goals.x, goals.y)].get_repr()=='+')
        {
            count++;
        }
    }
    for (auto &yellow_goals: yellow_goals_cell){
        if (level_cell[id(yellow_goals.x, yellow_goals.y)].get_repr()=='/'){
            count++;
        }
    }

    for(auto &purple_goals: purple_goals_cell){
        if (level_cell[id(purple_goals.x, purple_goals.y)].get_repr()=='*'){
            count++;
        }
    }
    return count;
}
void Sokoban::listen_game()
{
    if (get_goals_count() == goals_cell.size())
        {   
            printf("\nNice, you've succeeded lvl %d\n",level);
            level++;
            if (level == data_level.size()){printf("YOU WIN !!!\n"); exit(1);}
            printf("--> go to lvl %d\n",level);
            load_game();
            original_level.clear();
            for (auto &c:level_cell){original_level.push_back(c);}
        }
}

bool Sokoban::are_box_blocked(){

    vector<int>push_direction={0, 1, 2, 3};
    vector<Vector2D> box_list;
    int blocked_box = 0;
    int blocked_direction;
    bool first=true;

    for (int y=0;y<level_size.y;y++)
    {
        for (int x =0; x< level_size.x; x++)
        {
            switch (level_cell[y * level_size.x + x].get_repr())
            {
                case '$':
                case '+':
                /* {box_list.push_back(Vector2D{x,y});break;} */
                {
                    box_list.push_back(Vector2D{x,y});
                    cout<<"x= "<<x<<" y= "<<y<<endl;
                    break;
                }
            }
        }
    }

    /* cout<<"VOICI LES BOX: "<<get_box_list().size()<<endl; */
    /* for(size_t i =0; i<box_list.size(); i++){ */
    for(auto list_index: box_list){
        Vector2D box_pos {list_index.x, list_index.y};
        /* Vector2D c= {d.x, d.y}; */
        /* if (i>2){print_game();} */
        //int failed_check_move = 0;

        /* cout<<"BOXES:\nx= "<<c.x<<" y= "<<c.y<<endl; */
        for(int push_index = 0; push_index<= 3; push_index++){
            /* switch(push_index) */
            /* { */
            /*     case NORTH: c.y--;break; */
            /*     case SOUTH: c.y++;break; */
            /*     /1* case EAST: c.x--;break; *1/ */
            /*     /1* case WEST: c.x++;break; *1/ */
            /* } */
            /* cout<<"push index: "<<push_direction[push_index]<<endl; */
            /* cout<<"Coord: "<<box_list[i].x<<" "<<box_list[i].y<<endl; */
            
            
            /* if(check_move(box_list[i], push_direction[push_index]) == false){ */
            
            /* Vector2D r; */
            
            if(safe_check_move(box_pos, push_direction[push_index]) == false){
                if (first){

                    blocked_direction = push_index;
                    first = false;}
                else
                    if (abs(blocked_direction - push_index) % 2 == 1)
                        blocked_box ++;//bug provient du calcul
                        cout<<"blocked_box: "<<blocked_box<<endl;
                /* failed_check_move++; */
                /* if(failed_check_move >=2){ blocked_box++;break;} */
                //cout<<"Failed check move: \n"<<"case = "<<box_pos.x<<" "<<box_pos.y<<"\n"<<failed_check_move<<"dir=: "<<push_index<<endl;
                /* cout<<"BOXES2:\nx= "<<c.x<<" y= "<<c.y<<endl; */
            }
            /* c=d; */
            /* switch(push_index) */
            /* { */
            /*     case NORTH: c.y--;break; */
            /*     case SOUTH: c.y++;break; */
            /*     /1* case EAST: c.x--;break; *1/ */
            /*     /1* case WEST: c.x++;break; *1/ */
            /* } */
        }
    }
        /* cout<<"BLOCKED = "<<blocked_box<<endl; */

        /* if(blocked_box == box_list.size()){ return true; } */
        /* return false; */

    /* cout<<"BLOCK: "<<blocked_box<<endl; */
    return blocked_box == box_list.size();
}

bool Sokoban::is_lost(){

    int limited_step = level_data[2];
   
    if(used_step >= limited_step or are_box_blocked()){
        lost_flag = true;
    }

    return lost_flag;
}

bool Sokoban::safe_check_move(Vector2D current_pos, int push_dir){

    int verif=0;
    bool allow_pushing=false;
    bool test=true;
    bool repr;
    bool value;

    while(test)
    {
        switch (level_cell[id(current_pos.x, current_pos.y)].get_value())
        {
        case '$':
            verif++;
            if(verif >1){test=false;break;} //stop condition to not stop pushing a heavy box
            switch (push_dir){

                case NORTH: 
                    test = level_cell[id(current_pos.x, (current_pos.y)--)].get_value() == ' ';
                    break;
                case SOUTH: 
                    test = level_cell[id(current_pos.x, (current_pos.y)++)].get_value() == ' ';
                    break;
                case EAST: 
                    test = level_cell[id(current_pos.x++, current_pos.y)].get_value() == ' ';
                    break;
                case WEST: 
                    test = level_cell[id(current_pos.x--, current_pos.y)].get_value() == ' ';
                    break;
            }
            repr = level_cell[id(current_pos.x, current_pos.y)].get_repr() == '@';
            /* cout<<"repre= "<<level_cell[id(current_pos.x, current_pos.y)].get_repr()<<endl; */
            value = level_cell[id(current_pos.x, current_pos.y)].get_value() == ' ';
            allow_pushing =repr||value;
            /* cout<<"allow? "<<allow_pushing<<endl; */
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
        case '@':
            allow_pushing = true;
            test=false;

            /* switch(push_dir) */
            /* { */
            /*     case NORTH: current_pos.y--;break; */
            /*     case SOUTH: current_pos.y++;break; */
            /*     case EAST: current_pos.x--;break; */
            /*     case WEST: current_pos.x++;break; */
            /* } */

            break;
        }
    }
    /* cout<<"curr: "<<current_pos.x<<" y: "<<current_pos.y<<endl; */
    return allow_pushing;
}


bool Sokoban::check_move(Vector2D &current_pos, int push_dir)
{   
    int verif=0;
    bool allow_pushing=false;
    bool test=true;

    while(test)
    {
        switch (level_cell[id(current_pos.x, current_pos.y)].get_value())
        {
        case '$':
            verif++;
            if(verif >1){test=false;break;} //stop condition to not stop pushing a heavy box
            switch (push_dir)
            {
                case NORTH: 
                    test = level_cell[id(current_pos.x, (current_pos.y)--)].get_value() == ' ';
                    break;
                case SOUTH: 
                    test = level_cell[id(current_pos.x, (current_pos.y)++)].get_value() == ' ';
                    break;
                case EAST: 
                    test = level_cell[id(current_pos.x++, current_pos.y)].get_value() == ' ' ;
                    break;
                case WEST: 
                    test = level_cell[id(current_pos.x--, current_pos.y)].get_value() == ' ' ;
                    break;
            }
            allow_pushing = level_cell[id(current_pos.x, current_pos.y)].get_value() == ' ';
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
        case '@':
            allow_pushing = true;
            test=false;

            switch(push_dir)
            {
                case NORTH: current_pos.y--;break;
                case SOUTH: current_pos.y++;break;
                case EAST: current_pos.x--;break;
                case WEST: current_pos.x++;break;
            }

            break;
        }
    }
    return allow_pushing;
}

void Sokoban::draw()
{   
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_WHITE);
    int i=0;
    for (auto &c:level_cell)
    {
        if (c.get_value()!=' ' ){c.get_image()->draw(reverse_id(i).x*c.get_size(), reverse_id(i).y*c.get_size());}
        i++;
    }
    for (auto &goals:goals_cell)
    {   
        if (level_cell[id(goals.x, goals.y)].get_repr()=='.'||level_cell[id(goals.x, goals.y)].get_repr()==' ')
        { 
           Fl_Image *im = Fl_PNG_Image{"pika.png"}.copy(40,40);
		   im->draw(goals.x*50,goals.y*50);
        }
    }
    
}

void Sokoban::reset_level()
{
    level_cell.clear();
    for (auto&c:original_level)
    {
        level_cell.push_back(c);
    }
    pos_player.x=original_pos.x;
    pos_player.y=original_pos.y;
    used_step=0;
}

void Sokoban::next_level()
{   level++;

    if(used_step < level_data[1]){
        update_file(used_step);
    } 

    used_step=0;
    load_game();
    original_level.clear();
    for (auto &c:level_cell){original_level.push_back(c);}
}



int Sokoban::print_game()
{
    printf("\n");printf("SOKOBAN - GAME - level %d\n",level);
    for (auto &g:goals_cell){if (level_cell[id(g.x, g.y)].get_repr()==' '){level_cell[id(g.x, g.y)].set_repr('.');}}
    int i=0;string print_lvl="";for (auto &c:level_cell){print_lvl+=c.get_repr();i++;if (i==level_size.x ){print_lvl+="\n";i=0;}}cout <<print_lvl;
    for (auto &g:goals_cell){if (level_cell[id(g.x, g.y)].get_repr()=='.'){level_cell[id(g.x, g.y)].set_repr(' ');}}
    int count=0;for (auto &g:goals_cell){if (level_cell[id(g.x, g.y)].get_repr()=='$'|| level_cell[id(g.x, g.y)].get_repr()=='+'){count++;}}printf("%d / %lu\n", count, goals_cell.size());

    return count;
}  
