#ifndef _BOARD_H
#define _BOARD_H

#include <string>
#include <iostream>
#include <vector>
#include <memory>
using std::string;
using std::vector;
using std::unique_ptr;
using namespace std;

typedef struct vector_2D
{
    int x,y;
};

class Board{
    private:
    vector_2D level_size={20,10};
    vector_2D block_size={10,10};
    vector_2D player_position;

    public:
    Board()=default;
    ~Board()=default;
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
    vector <unique_ptr<int>> level_vector;// changer int en type du block

    virtual vector_2D get_level_size(){
        return level_size;
    }

    virtual vector_2D get_block_size(){
        return block_size;
    }

    virtual vector_2D get_player_position(){
        return player_position;
    }

    virtual void set_player_position(int x, int y);

    virtual int id (int x, int y); 
    /**
     * @brief : attribute an id to every objects in the vector to simulate a matrix
     */
    
    
    virtual void load_level();
    /**
     * @brief: Browse the board and add to a vector the object mapped with the symbol in the board
     */

    virtual bool check_moves(vector_2D actual_player_position, int push_direction);
    /**
     * @brief: check if the movement asked by the player is possible
     * @param actual_player_position: position in x and y of the player
     * @param push_direction: the direction where the player want to move
     */

    virtual bool win_condition();
    /**
     * @brief: check if all the boxes are on the objectives points 
     * @return: true if the player won false if the game is not finished
     */

    virtual void play_move(vector_2D &current_block, int push_direction);
    /**
     * @brief: play the move on the board 
     */
};


#endif
