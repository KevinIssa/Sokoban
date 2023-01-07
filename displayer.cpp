#include "displayer.hpp"
#include "case.hpp"
/* #include <FL/Enumerations.H> */
#include <FL/Fl_Image.H>


/* void Displayer::display_element(const char cell_repr, vector <Vector2D> goal_list, Fl_Image* picture){ */

/*     player_img->draw(player_pos.x*BOX_SIZE, player_pos.y*BOX_SIZE); */
/*     for (auto &goal:goal_list){ */

/*         if (soko->get_level_cell()[soko->id(goal.x, goal.y)].get_repr()== cell_repr */
/*         ||soko->get_level_cell()[soko->id(goal.x, goal.y)].get_repr()==' ') */
/*         { */  
/*             picture->draw(goal.x*BOX_SIZE, goal.y*BOX_SIZE); */
/*         } */
/*     } */
/* } */


void Displayer::display_element(const char cell_repr, vector <Vector2D> goal_list, Fl_Image* picture){
    Case *current_case;
    player_img->draw(player_pos.x*BOX_SIZE, player_pos.y*BOX_SIZE);
    for (auto &goal:goal_list){
        current_case = &soko->get_level_cell()[soko->id(goal.x, goal.y)];
        if (current_case->get_repr() == cell_repr or current_case->get_repr() == ' ')

        /* if (soko->get_level_cell()[soko->id(goal.x, goal.y)].get_repr()== cell_repr */
        /* ||soko->get_level_cell()[soko->id(goal.x, goal.y)].get_repr()==' ') */
        {  
            picture->draw(goal.x*BOX_SIZE, goal.y*BOX_SIZE);
        }
    }
}

void Displayer::draw(){
    /* fl_draw_box(FL_FLAT_BOX, BEGIN_X, BEGIN_Y, GAME_SIZE, GAME_SIZE, FL_WHITE); */
    /* fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE , FL_RED); */
    /* fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE , FL_BLUE); */
    /* fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , FL_GREEN); */
    normal_goals = soko->get_normal_goals();
    purple_goals = soko->get_purple_goals();
    yellow_goals = soko->get_yellow_goals();
    teleporter_cells= soko->get_teleporter_cell(); 
    box_list = soko->get_box_list(); 
    player_pos = soko->get_pos_player();
    wall_list = soko ->get_wall_cell();
    
    display_element('.', normal_goals, normal_goals_img );
    display_element('/', yellow_goals, yellow_goals_img );
    display_element('*', purple_goals, purple_goals_img );
    display_element('&',teleporter_cells, teleporter_cells_img );

    display_element('$', box_list, normal_box_img );
    display_element('H', box_list, yellow_box_img );
    display_element('M', box_list, purple_box_img );
    display_element('+', box_list, light_box_img );
    display_element('#', wall_list, wall_img);
}



void Displayer::draw_menu(){
    fl_draw_box(FL_FLAT_BOX, BEGIN_X, BEGIN_Y, GAME_SIZE, GAME_SIZE, FL_RED);
}
void Displayer::draw_end_game(){
    draw();
    fl_draw_box(FL_FLAT_BOX, GAME_SIZE + 10 , BEGIN_Y + 10 , BOX_SIZE, BOX_SIZE + 10, FL_RED);

}

void Displayer::draw_button(){
    fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE , FL_RED);
    fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE , FL_BLUE);
    fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , FL_GREEN);
    fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE , FL_WHITE);

}




