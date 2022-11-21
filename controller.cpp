#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
#include "controller.hpp"


int Controller::process_key(int event)
{
    tup position = soko->get_pos_player();

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
    if (soko->get_score() == soko->get_goals_v().size())
        {   
            printf("\nNice, you've succeeded lvl %d\n",soko->get_level()+1);
            if (soko->get_level() + 1 ==soko->get_data_level().size()){printf("YOU WIN !!!\n"); exit(1);}
            printf("--> go to lvl %d\n",soko->get_level()+1);
            soko->next_level();
        }
}


