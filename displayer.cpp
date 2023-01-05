#include "displayer.hpp"

void Displayer::draw(){
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_WHITE);
    int i=0;
    for (auto &c:soko->get_level_cell())
    {
        if (c.get_value()!=' ' and c.get_value() != TELEPORTER ){
            c.get_image()->draw(soko->reverse_id(i).x*c.get_size(), soko->reverse_id(i).y*c.get_size());
        }
        i++;
    }

    for (auto &goal:soko->get_normal_cell()){

        if (soko->get_level_cell()[soko->id(goal.x, goal.y)].get_repr()=='.'
        ||soko->get_level_cell()[soko->id(goal.x, goal.y)].get_repr()==' ')
        {  
            Fl_Image *im =Fl_PNG_Image {"pika.png"} .copy(50,50);
            im->draw(goal.x*50, goal.y*50);
        }
    }

    for(auto &yellow_goal: soko->get_yellow_cell()){

        if (soko->get_level_cell()[soko->id(yellow_goal.x, yellow_goal.y)].get_repr() == '/'
        ||soko->get_level_cell()[soko->id(yellow_goal.x, yellow_goal.y)].get_repr()==' '){
            Fl_Image *im =Fl_PNG_Image {"elekable.png"} .copy(50,50);
            im->draw(yellow_goal.x*50, yellow_goal.y*50);
        }
    }

    for(auto &purple_cell: soko->get_purple_cell()){

        if (soko->get_level_cell()[soko->id(purple_cell.x, purple_cell.y)].get_repr() == '*'
        ||soko->get_level_cell()[soko->id(purple_cell.x, purple_cell.y)].get_repr()==' '){
            Fl_Image *im =Fl_PNG_Image {"giratina.png"} .copy(50,50);
            im->draw(purple_cell.x*50, purple_cell.y*50);
        } 
    }

    for(auto &teleporter: soko->get_teleporter_cell()){
        if (soko->get_level_cell()[soko->id(teleporter.x, teleporter.y)].get_repr() == '&'
        ||soko->get_level_cell()[soko->id(teleporter.x, teleporter.y)].get_repr()==' '){
            Fl_Image *im =Fl_PNG_Image {"teleporter.png"} .copy(50,50);
            im->draw(teleporter.x*50, teleporter.y*50);
        } 
    }
}
void Displayer::draw_menu(){
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_RED);
}
