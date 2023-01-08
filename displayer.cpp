#include "displayer.hpp"
#include "buttonUI.hpp"
#include <FL/Enumerations.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Window.H>
#include <cstdio>
#include <iostream>
#include <string>

void Displayer::display_element(const char cell_repr, vector <Vector2D> goal_list, Fl_Image* picture){
    Case *current_case;

    for (auto &goal:goal_list){
        current_case = &soko->get_level_cell()[soko->id(goal.x, goal.y)];
        if (current_case->get_repr() == cell_repr or current_case->get_repr() == ' ')

        {  
            picture->draw(goal.x*BOX_SIZE, goal.y*BOX_SIZE);
        }
    }
}


void Displayer::init_all(){
    
    auto image_gen = [](const char * s)  {return Fl_PNG_Image {s} .copy(BOX_SIZE,BOX_SIZE);};
    image_list.push_back(image_gen("player.png"));
    image_list.push_back(image_gen("pika.png"));
    image_list.push_back(image_gen("elekable.png"));
    image_list.push_back(image_gen("giratina.png"));
    image_list.push_back(image_gen("teleporter.png"));
    image_list.push_back(image_gen("pokeball.png"));
    image_list.push_back(image_gen("superball.png"));
    image_list.push_back(image_gen("master_ball.png"));
    image_list.push_back(image_gen("hyper_ball.png"));
    image_list.push_back(image_gen("grey_wall.png"));
        
}

void Displayer::draw(){

    normal_goals = soko->get_normal_goals();
    purple_goals = soko->get_purple_goals();
    yellow_goals = soko->get_yellow_goals();
    teleporter_cells= soko->get_teleporter_cell(); 
    box_list = soko->get_box_list(); 
    player_pos.clear();
    player_pos.push_back(soko->get_pos_player());
    wall_list = soko ->get_wall_cell();
   

    display_element('@', player_pos, image_list[0]  );
    display_element('.', normal_goals, image_list[1]  );
    display_element('/', yellow_goals, image_list[2] );
    display_element('*', purple_goals, image_list[3] );
    display_element('&',teleporter_cells,image_list[4] );

    display_element('$', box_list,  image_list[5] );
    display_element('+', box_list, image_list[6] );
    display_element('M', box_list, image_list[7] );
    display_element('H', box_list, image_list[8]  );
    display_element('#', wall_list, image_list[9]);
}


void Displayer::draw_menu(){
    fl_draw_box(FL_FLAT_BOX, BEGIN_X, BEGIN_Y, GAME_SIZE, GAME_SIZE, FL_RED);
}
void Displayer::draw_end_game(){
    draw();
    fl_draw_box(FL_FLAT_BOX, GAME_SIZE + 10 , BEGIN_Y + 10 , BOX_SIZE, BOX_SIZE + 10, FL_RED);

}

void Displayer::draw_button(){
    char level[20] = "";
    
    sprintf(level,"%d", soko->get_level());

    ButtonUI lvl = ButtonUI{FL_WHITE, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 50, level};
    button_list.push_back(lvl);
    
    char reset[20] = "";
    sprintf(reset,"RESET");
    ButtonUI reset_lvl = ButtonUI{FL_YELLOW, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 30, reset}; 

    button_list.push_back(reset_lvl);

    char quit[20] = "";
    sprintf(quit,"QUIT");
    ButtonUI quit_but = ButtonUI{FL_GREEN, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 25, quit}; 
    button_list.push_back(quit_but);
    
    char b_score[20] = "";
    sprintf(b_score,"BEST = %d", soko->get_best_score());

    ButtonUI best_score=ButtonUI {FL_RED,  GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 3*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 15, b_score}; 
    button_list.push_back(best_score);

    char score_b[20] = "";
    sprintf(score_b, "%d/%d", soko->get_used_step(), soko->get_limited_step());
    
    Fl_Color col = FL_MAGENTA;

    if(soko->is_lost() == 1){
        col = FL_RED;
    }

    ButtonUI score = ButtonUI{col,  GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE, 25, score_b}; 
    button_list.push_back(score);

    fl_font(FL_HELVETICA,30);
    fl_color(fl_rgb_color(0,0,255));

    if(soko->is_lost() == 2){ 

        fl_draw("BLOCKED", GAME_SIZE - 2*BOX_SIZE ,5*BOX_SIZE, 7*BOX_SIZE, 2*BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false);//j'ai creer un fichier original_leveles pour ca
    }

    char chg_lvl_p[20] = "";
    sprintf(chg_lvl_p,"Previous Level");
    ButtonUI chg_lvl_prev = ButtonUI{FL_CYAN,  OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, chg_lvl_p}; 
    button_list.push_back(chg_lvl_prev);

    char chg_lvl_n[20] = "";
    sprintf(chg_lvl_n,"Next Level");
    ButtonUI chg_lvl = ButtonUI{FL_CYAN,  2*OFFSET_BUTTON + 3*BOX_SIZE ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, chg_lvl_n}; 
    button_list.push_back(chg_lvl);
    
    char reset_all_b[20] = "";
    ButtonUI reset_all = ButtonUI{FL_BLUE, GAME_SIZE + 3*BOX_SIZE-BOX_SIZE/2 ,10*BOX_SIZE + BOX_SIZE/(5/2) , BOX_SIZE/5, BOX_SIZE/5 , 20, reset_all_b}; 
    button_list.push_back(reset_all);
    

    fl_font(FL_HELVETICA,20);

    fl_draw("reset all data ------>", GAME_SIZE-BOX_SIZE/2 ,9*BOX_SIZE, 2*BOX_SIZE, 3*BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false);

  for (auto &b:button_list) {
    b.draw();
  }
}
