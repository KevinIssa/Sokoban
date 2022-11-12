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
    bool win_condition();
    bool check_moves();
    void play_move();

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
                        level_vector.emplace_back(make_unique < Light_block>(vector_2D{x,y},block_size.x,block_size.y));
                        break;
                    case '@':
                        level_vector.emplace_back(make_unique < Player>(vector_2D{x,y},block_size.x,block_size.y));
                        player_position.x = x; player_position.y = y;
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

bool Board::win_condition(){
            tuple current_block = player_position;
            bool allow_pushing = false;
            bool test = true;
            
            while(test)  //test in one way
            {
                if (level_vector [id(current_block)] != nullptr)
                {
                    if (level_vector[id(current_block)]->push((push_direction + 2) % 4))
                    {
                        //bloc peut bouger
                        switch (push_direction)
                        {
                            case NORTH: current_block.y--; break;
                            case SOUTH: current_block.y++; break;
                            case EAST: current_block.x++; break;
                            case WEST: current_block.x--; break;
                        }
                        // if (current_block == Heavy_block && current_block + 1 is_empty)
                    }
                    else
                        test = false;
                }
                else
                {
                    allow_pushing = true;
                    test = false;
                }
            }
}