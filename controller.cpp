#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
#include "controller.h"


int Controller::process_key(int event)
{
    tup position = soko->get_pos_player();

    switch(event)
    {
        case 'z':
            position.y--;
            if(soko->check_move(position, NORTH)){soko->play_move(position, NORTH);};
            break;
        case 's':
            position.y++;
            if(soko->check_move(position, SOUTH)){soko->play_move(position, SOUTH);};
            break;
        case 'q':
            position.x--;
            if(soko->check_move(position, WEST)){soko->play_move(position, WEST);};
            break;
        case 'd':
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
            // niveau++;
            // soko->set_level(soko->get_level()+1);
            if (soko->get_level() + 1 ==soko->get_data_level().size()){printf("YOU WIN !!!\n"); exit(1);}
            printf("--> go to lvl %d\n",soko->get_level()+1);
            soko->next_level();


            // soko->load_game();
            // original_level.clear();
            // for (auto &c:level_c){original_level.push_back(c);}
            // print_game();
        }
}


