#include "displayer.hpp"

void Displayer::draw(){
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_WHITE);
    int i=0;
    for (auto &c:soko->get_level_cell())
    {
        if (c.get_value()!=' ' ){c.get_image()->draw(soko->reverse_id(i).x*c.get_size(), soko->reverse_id(i).y*c.get_size());}
        i++;
    }

    for (auto &goals:soko->get_goals_cell())
    {   
        if (soko->get_level_cell()[soko->id(goals.x, goals.y)].get_repr()=='.'
        ||soko->get_level_cell()[soko->id(goals.x, goals.y)].get_repr()==' ')
        {  
            Fl_Image *im =Fl_PNG_Image {"pika.png"} .copy(50,50);
            im->draw(goals.x*50, goals.y*50);
        }
    }
}
void Displayer::draw_menu(){
    fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_RED);
}
