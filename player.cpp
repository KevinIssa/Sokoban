#include "player.h"

void Player::player_input(int keycode, int &push_direction){
    switch (keycode)
    {
    case 'z':
        push_direction = NORTH;
        break;
    
    case 's':
        push_direction = SOUTH;
        break;
    
    case 'q':
        push_direction = WEST;
        break;

    case 'd':
        push_direction = EAST;
        break;
    
    case ' '
        load_level();
        break;
    }

}

