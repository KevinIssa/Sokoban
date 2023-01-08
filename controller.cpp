#include "controller.hpp"
#include "buttonUI.hpp"


int Controller::process_key(int event)
{
    Vector2D position = soko->get_pos_player();

    switch(event) //movement asked with arrows or normal keys
    {
        case 'z': case UP_KEY: 
            position.y--;
            if(soko->check_move(position, NORTH)){soko->play_move(position, NORTH);};
            if(soko->can_tp_end()){soko->end_tp();};
            soko->fill_box_list();
            break;
        
        case 's': case DOWN_KEY:
            position.y++;
            if(soko->check_move(position, SOUTH)){soko->play_move(position, SOUTH);};
            if(soko->can_tp_end()){soko->end_tp();};
            soko->fill_box_list();
            break;
        
        case 'q': case LEFT_KEY:
            position.x--;
            if(soko->check_move(position, WEST)){soko->play_move(position, WEST);};
            if(soko->can_tp_end()){soko->end_tp();};
            soko->fill_box_list();
            break;
        
        case 'd': case RIGHT_KEY:
            position.x++;
            if(soko->check_move(position, EAST)){soko->play_move(position, EAST);};
            if(soko->can_tp_end()){soko->end_tp();};
            soko->fill_box_list();
            break;
       
        case 'r':
            soko->reset_level();
            soko->fill_box_list();
            break;
        case 'p':
            printf("GAME OVER !!!\n");exit(0);
    }
return 0;
}

void Controller::listen_game()
{   
    int value_type = soko->is_lost();
    if (soko->get_goals_count() == soko->get_goals_cell().size()){ 

            printf("\nNice, you've succeeded lvl %d\n",soko->get_level());
            if (soko->get_level() == soko->get_data_level().size()){
                printf("YOU WIN !!!\n"); 
                exit(1);
            }
            printf("--> go to lvl %d\n",soko->get_level()+1);
            
            try{
            soko->chg_save_flag();
            soko->next_level(1);
            soko->chg_save_flag();
            }
            
        catch(...){
            cout<<"YOU WIN !!!"<<endl;
            exit(1);
        }
    }

    else if(value_type == 1){
        cout<<"You lost! You used too many step!"<<endl;
    } 

    else if (value_type == 2){
        cout<<"You lost! All boxes are blocked!"<<endl;
    }
    /* cout <<"vzlue= "<<value_type<<endl; */
}
void Controller::quit_game() {
    printf("GAME OVER !!!\n");exit(0);

    /* cout<<"aaaaaaaaaaaaaa"<<endl; */
  /* for (auto &b:button_list) b->mouseClick(mouseLoc); */
}
void Controller::reset_all_data() {
    /* soko->reset_level(); */
    /* soko->fill_box_list(); */
soko->reset_data();
    /* cout<<"aaaaaaaaaaaaaa"<<endl; */
  /* for (auto &b:button_list) b->mouseClick(mouseLoc); */
}
void Controller::change_lvl(int offset_level) {
    try{
        /* soko->chg_save_flag(); */
        soko->next_level(offset_level);
        /* soko->chg_save_flag(); */
        }
            
    catch(...){
        cout<<"Bye Bye !!!"<<endl;
        exit(1);
        }

    /* soko->reset_level(); */
    /* soko->fill_box_list(); */

    /* cout<<"aaaaaaaaaaaaaa"<<endl; */
  /* for (auto &b:button_list) b->mouseClick(mouseLoc); */
}
void Controller::reset_game() {
    soko->reset_level();
    soko->fill_box_list();

    /* cout<<"aaaaaaaaaaaaaa"<<endl; */
  /* for (auto &b:button_list) b->mouseClick(mouseLoc); */
}

/* void Controller::quit_game() */
void Controller::mouseClick(Vector2D mouseLoc) {
    /* cout<<"CLICK"<<endl; */
  for (auto &b:button_list) b->mouseClick(mouseLoc);
}

void Controller::init() {
    
    char buffer[20]="";
    for (auto &b:button_list) delete b;
    button_list.clear();
    Clickable_ButtonUI *reset = new Reset_ButtonUI { FL_YELLOW, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON  + BOX_SIZE + OFFSET_BUTTON , 2*BOX_SIZE, BOX_SIZE, 30, buffer, this };
    button_list.push_back(reset);
    Clickable_ButtonUI *quit = new Quit_ButtonUI { FL_GREEN, GAME_SIZE + OFFSET_BUTTON , BEGIN_Y + OFFSET_BUTTON + 2*(BOX_SIZE+OFFSET_BUTTON), 2*BOX_SIZE, BOX_SIZE , 25,buffer, this };
    button_list.push_back(quit);
    Clickable_ButtonUI *next_lvl = new Next_level_ButtonUI { FL_CYAN,  2*OFFSET_BUTTON + 3*BOX_SIZE ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2 , 20, buffer, this };
    button_list.push_back(next_lvl);
    Clickable_ButtonUI *prev_lvl = new Previous_level_ButtonUI { FL_CYAN, OFFSET_BUTTON ,GAME_SIZE + OFFSET_BUTTON, 3*BOX_SIZE, BOX_SIZE/2, 20, buffer, this };
    button_list.push_back(prev_lvl);
    Clickable_ButtonUI *reset_all = new Reset_all_ButtonUI { FL_BLUE, GAME_SIZE + 3*BOX_SIZE-BOX_SIZE/2 ,10*BOX_SIZE + BOX_SIZE/(5/2) , BOX_SIZE/5, BOX_SIZE/5 , 20,buffer, this  };
    button_list.push_back(reset_all);



}
