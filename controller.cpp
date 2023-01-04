#include "controller.hpp"


int Controller::process_key(int event)
{
    Vector2D position = soko->get_pos_player();

    switch(event) //fleches actives
    {
        case 'z':
            position.y--;
            if(soko->check_move(position, NORTH)){soko->play_move(position, NORTH);};
            break;
        case 65362: 
            position.y--;
            if(soko->check_move(position, NORTH)){soko->play_move(position, NORTH);};
            break;
        case 's':
            position.y++;
            if(soko->check_move(position, SOUTH)){soko->play_move(position, SOUTH);};
            break;
        case 65364:
            position.y++;
            if(soko->check_move(position, SOUTH)){soko->play_move(position, SOUTH);};
            break;
        case 'q':
            position.x--;
            if(soko->check_move(position, WEST)){soko->play_move(position, WEST);};
            break;
        case 65361:
            position.x--;
            if(soko->check_move(position, WEST)){soko->play_move(position, WEST);};
            break;
        case 'd':
            position.x++;
            if(soko->check_move(position, EAST)){soko->play_move(position, EAST);};
            break;
        case 65363:
            position.x++;
            if(soko->check_move(position, EAST)){soko->play_move(position, EAST);};
            break;
        case 'r':
            soko->reset_level();
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
            if (soko->get_level() == soko->get_data_level().size()){printf("YOU WIN !!!\n"); exit(1);}
            printf("--> go to lvl %d\n",soko->get_level()+1);
            
            try{
            soko->next_level();
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
}


