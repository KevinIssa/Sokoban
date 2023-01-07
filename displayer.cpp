#include "displayer.hpp"
/* #include "case.hpp" */
/* #include "button.hpp" */
/* #include <FL/Enumerations.H> */
#include <FL/Enumerations.H>
#include <FL/Fl_Image.H>
#include <FL/Fl_Window.H>
#include <cstdio>
#include <iostream>


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
    /* draw_button(); */
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



void Displayer::draw_button(){//Si tu veux refactor en focntions ici, tu peux remarquer que les arguments de positions sont les meme dans 
    /* for (auto */
        char level[20]="";
       


        cout<<"level= "<<soko->get_level()<<endl;
        /* sleep(5); */
        sprintf(level,"%d", soko->get_level());
        cout<<"avant objet: "<<level<<endl;
        Button *lvl = new Button(FL_WHITE, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 50, level);
        button_list.push_back(lvl);
        lvl->foo();
        
        char reset[20]="";
        sprintf(reset,"RESET");
        Button *reset_lvl = new Button(FL_YELLOW, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 35, reset); 
        /* memset(reset, 0, 20); */ 
        button_list.push_back(reset_lvl);

        char quit[20]="";
        sprintf(quit,"QUIT");
        Button *quit_but = new Button(FL_GREEN, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 25, quit); 
        button_list.push_back(quit_but);
        /* memset(buffer, 0, 20); */ 
        



        char b_score[20]="";
        sprintf(b_score,"BEST = %d", soko->get_best_score());
        Button *best_score = new Button(FL_RED,  GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 3*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 15, b_score); 
        button_list.push_back(best_score);
        /* memset(buffer, 0, 20); */ 

        char score_b[20]="";
        sprintf(score_b, "%d/%d", soko->get_used_step(), soko->get_limited_step());
        Button *score = new Button(FL_MAGENTA,  GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE, 25, score_b); 
        button_list.push_back(score);


        char chg_lvl_b[20]="";
        sprintf(chg_lvl_b,"Change Level");
        Button *chg_lvl = new Button(FL_CYAN,  OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, chg_lvl_b); 
        button_list.push_back(chg_lvl);
        /* memset(buffer, 0, 20); */ 

        /* sprintf(buffer,""); */
        char reset_all_b[20]="";
        Button *reset_all = new Button(FL_CYAN,  OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, reset_all_b); 
        button_list.push_back(reset_all);
        /* memset(buffer, 0, 20); */ 



  for (auto &b:button_list) {b->draw();
      /* b->foo(); */
  }
}
/* void Displayer::draw_button(){//Si tu veux refactor en focntions ici, tu peux remarquer que les arguments de positions sont les meme dans */ 
/*                               //les box et dans les textes. on peut faire un heritage ici clairement je pense si tu te chauffe. */
/*                               //pour l'instant ce ne sont que des cases il faut bind une fonction pour certains */


/*     /1* fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE , FL_RED); *1/ */
/*     fl_font(FL_HELVETICA,50); */
/*     fl_color(fl_rgb_color(0,0,255)); */
/*     char level[10]=""; */
/*     sprintf(level,"%d", soko->get_level()); */
/*     fl_draw(level,GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false); */
    
/*     fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE , FL_YELLOW); */
/*     fl_font(FL_HELVETICA,25); */
/*     fl_color(fl_rgb_color(0,0,255)); */
/*     fl_draw("RESET", GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false); */

/*     fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , FL_GREEN); */
/*     fl_font(FL_HELVETICA,35); */
/*     fl_color(fl_rgb_color(0,0,255)); */
/*     fl_draw("QUIT", GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false); */

/*     fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 3*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , FL_RED); */
/*     fl_font(FL_HELVETICA,15); */
/*     fl_color(fl_rgb_color(0,0,255)); */
/*     char best[10]=""; */
/*     sprintf(best,"BEST = %d", soko->get_best_score()); */
/*     fl_draw(best, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 3*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false); */







/*     fl_draw_box(FL_FLAT_BOX, GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE , FL_MAGENTA); */
/*     fl_font(FL_HELVETICA,25); */
/*     fl_color(fl_rgb_color(0,0,255)); */
/*     char score[10]=""; */
/*     sprintf(score, "%d/%d", soko->get_used_step(), soko->get_limited_step()); */
/*     fl_draw(score, GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false); */

/*     fl_draw_box(FL_FLAT_BOX, OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , FL_CYAN);//ici un changement d'ecran sera afficher si cliquer dessus */
/*     fl_font(FL_HELVETICA,20); */
/*     fl_color(fl_rgb_color(0,0,255)); */
/*     fl_draw("Change Level",  OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 ,FL_ALIGN_CENTER,nullptr,false); */




/*     fl_draw("reset all data --->", GAME_SIZE-BOX_SIZE/2 ,9*BOX_SIZE, 2*BOX_SIZE, 3*BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false);//j'ai creer un fichier original_leveles pour ca */
/*     fl_draw_box(FL_FLAT_BOX, GAME_SIZE + 3*BOX_SIZE-BOX_SIZE/2 ,10*BOX_SIZE+BOX_SIZE/2.5, BOX_SIZE/5, BOX_SIZE/5 , FL_BLUE); */
    
/*     /1* fl_draw("100/100", GAME_SIZE + OFFSET_BUTTON ,8*BOX_SIZE, 2*BOX_SIZE, 2*BOX_SIZE ,FL_ALIGN_CENTER,nullptr,false); *1/ */
/*     /1* sleep(5); *1/ */


/* } */

/* bool Rectangle::contains(Point p) { */
/*   return p.x >= center.x-w/2 && */
/*          p.x < center.x+w/2 && */
/*          p.y >= center.y-h/2 && */
/*          p.y < center.y+h/2; */
/* } */



/* void Cell::mouseClick(Point mouseLoc) { */
/*   if (r.contains(mouseLoc)) { */
/*     on = !on; */
/*     if (on) */
/*       r.setFillColor(FL_YELLOW); */
/*     else */
/*       r.setFillColor(FL_WHITE); */
/*   } */
/* } */



/* void Controller::mouseClick(Point mouseLoc) { */
/*   for (auto &c:cells) c.mouseClick(yymouseLoc); */
/* } */


