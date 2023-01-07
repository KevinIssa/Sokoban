#include "displayer.hpp"

void Displayer::display_goals(const char cell_repr, vector <Vector2D> goal_list, const char* picture){

    for (auto &goal:goal_list){

        if (soko->get_level_cell()[soko->id(goal.x, goal.y)].get_repr()== cell_repr
        ||soko->get_level_cell()[soko->id(goal.x, goal.y)].get_repr()==' ')
        {  
            Fl_Image *im =Fl_PNG_Image {picture} .copy(50,50);
            im->draw(goal.x*50, goal.y*50);
        }
    }
}

void Displayer::draw(){
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_WHITE);
    int i=0;

    vector <Vector2D> normal_goals = soko->get_normal_goals();
    vector <Vector2D> purple_goals = soko->get_purple_goals();
    vector <Vector2D> yellow_goals = soko->get_yellow_goals();
    vector <Vector2D> teleporter_cells= soko->get_teleporter_cell(); 
    vector <Vector2D> box_list = soko->get_box_list(); 
    Vector2D player_pos = soko->get_pos_player();

    Fl_Image *im =Fl_PNG_Image {"player.png"} .copy(50,50);
    im->draw(player_pos.x*50, player_pos.y*50);
    
    for(auto &wall: soko->get_wall_cell()){
            Fl_Image *im =Fl_PNG_Image {"grey_wall.png"} .copy(50,50);
            im->draw(wall.x*50, wall.y*50);

    }
    
    for (auto &c:soko->get_level_cell())
    {
        if (c.get_repr()=='$'  or c.get_repr() == 'H' or c.get_repr() == 'M' or c.get_repr() =='+'){
            /* c.get_image()->draw(soko->reverse_id(i).x*c.get_size(), soko->reverse_id(i).y*c.get_size()); */
        }
        i++;
    }

    display_goals('.', normal_goals, "pika.png" );
    display_goals('/', yellow_goals, "elekable.png" );
    display_goals('*', purple_goals, "giratina.png" );
    display_goals('&',teleporter_cells, "teleporter.png" );

    display_goals('$', box_list, "pokeball.png" );
    display_goals('H', box_list, "hyper_ball.png" );
    display_goals('M', box_list, "master_ball.png" );
    display_goals('+', box_list, "superball.png" );
}



void Displayer::draw_menu(){
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_RED);
}







