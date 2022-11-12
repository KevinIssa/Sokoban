#include <string>
#include <iostream>
#include <vector>
#include <memory>
using std::string;
using std::vector;
using std::unique_ptr;
using namespace std;

struct vector_2D
{
    int x,y;
};


class Board{
    private:
    vector_2D level_size={20,10};
    vector_2D block_size={10,10};
    vector_2D player_position;

    public:
    string board_level = 
        "####################"
        "#                  #"
        "#  $         $     #"
        "#      .           #"
        "#                  #"
        "#       @     $    #"
        "#                  #"  
        "#      #     .     #"
        "# .     #          #"
        "####################";
    
    vector<vector_2D>objectives_list;
    vector <unique_ptr<block>> level_vector;

    vector_2D get_level_size(){
        return level_size;
    }

    vector_2D get_block_size(){
        return block_size;
    }

    vector_2D get_player_position(){
        return player_position;
    }

    void set_player_position(int x, int y){
        player_position={x,y};
    }

    void load_level();
    bool check_moves(vector_2D actual_player_position, int push_direction);
    bool win_condition();
    int id (int x, int y) { 
        return y * get_level_size().x + x; 
    }
    void play_move(vector_2D actual_position, vector_2D final_position);

};

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
    int goals_win=0;
    for (auto& position_index: objectives_list)
    {
        if (level_vector[id(position_index.x,position_index.y)] 
        && level_vector[id(position_index.x,position_index.y)].isbox())
        goals_win++;
    }

    return goals_win == objectives_list.size();
}

void Board:: play_move(vector_2D actual_position, vector_2D final_position){
    
}
