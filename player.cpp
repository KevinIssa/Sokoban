#include "player.h"


Player::Player (vector_2D center, int width, int height):
    r(center, width, height, FL_WHITE, FL_WHITE){}

void Player::player_input(&push_direction){

        if (GetKey("z").bpressed)
        {
            push_direction = NORTH;
        }
        if (GetKey("s").bpressed)
        {
            push_direction = SOUTH;
        }
        if (GetKey("q").bpressed)
        {
            push_direction = WEST;
        }
        if (GetKey("d").bpressed)
        {
            push_direction = EAST;
        }
        if (GetKey("r").bpressed)
        {
            load_level();
        }

}

