#include "board.h"

void Board::set_player_position(int x, int y){
    player_position={x,y};
}
int Board::id(int x, int y){
    return y * get_level_size().x + x; 
}
void Board::load_level(){
    objectives_list.clear();
    level_vector.clear();

    for (int x = 0; x < level_size.x; x++){

            for (int y=0; y< level_size.y; y++){

                switch (board_level[y * level_size.x + x]){
                    case '#':
                        level_vector.emplace_back(make_unique < Wall>(vector_2D{x,y},block_size.x,block_size.y));
                        break;
                    case '$':
                        level_vector.emplace_back(make_unique < Light_box>(vector_2D{x,y},block_size.x,block_size.y));
                        break;
                    case '@':
                        level_vector.emplace_back(make_unique < Player>(vector_2D{x,y},block_size.x,block_size.y));
                        player_position.x = x; player_position.y = y;
                        break;
                    case '+':
                        level_vector.emplace_back(make_unique < Box>(vector_2D(x,y),block_size.x,block_size.y));
                        break;

                    case '.':
                        level_vector.emplace_back(nullptr);
                        objectives_list.push_back({x, y});
                        break;
                    
                    default:
                        level_vector.emplace_back(nullptr);

                }
            }
    }
};

bool Board::check_moves(vector_2D actual_player_position, int push_direction){
    vector_2D current_block = actual_player_position;
    // function who attribuate a value (x,y) as an id for a cell
    bool allow_pushing = false;
    bool stop_flag = true;
    
    while(stop_flag)  //test in one way
    {
        //check if the block we want to go is empty
        if (level_vector [id(current_block.x,current_block.y)] != nullptr)
        {
            //check if the block can be pushed
            if (level_vector[id(current_block.x,current_block.y)]->push((push_direction + 2) % 4))
            {
                //block can move
                switch (push_direction)
                {
                    case NORTH: current_block.y--; break;
                    case SOUTH: current_block.y++; break;
                    case EAST: current_block.x++; break;
                    case WEST: current_block.x--; break;
                }
            }
            else
                stop_flag = false;
        }
        else
        {
            allow_pushing = true;
            stop_flag = false;
        }
    }
    return allow_pushing;
}

bool Board::win_condition(){
    int objectives_win=0;
    for (auto& position_index: objectives_list)
    {
        if (level_vector[id(position_index.x,position_index.y)] 
        && level_vector[id(position_index.x,position_index.y)].isbox())
        objectives_win++;
    }

    return objectives_win == objectives_list.size();
}

void Board:: play_move(vector_2D &current_block, int push_direction){
    while(current_block.x != player_position.x && current_block.y !=player_position.y){
        vector_2D source = current_block;
        switch (push_direction)
        {
            case NORTH: source.y++; break;
            case SOUTH: source.y--; break;
            case EAST: source.x--; break;
            case WEST: source.x++; break;
        }
        if (level_vector[id(source.x,source.y)] =! nullptr){
            level_vector[id(source.x,source.y)]->move();
        }

        swap(level_vector[id(source.x,source.y)], level_vector[id(current_block.x,current_block.y)]);
        current_block = source;     
    }
    switch (push_direction)
    {
        case NORTH: player_position.y--; break;
        case SOUTH: player_position.y++; break;
        case EAST: player_position.x++; break;
        case WEST: player_position.x--; break;
    }

}
