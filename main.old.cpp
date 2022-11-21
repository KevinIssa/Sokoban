#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <windows.h> // for the GetKey function, have to find an alternative with fltk
// levels : https://github.com/deepmind/boxoban-levels

using namespace std;

constexpr NORTH = 0;
constexpr EAST = 1;
constexpr SOUTH = 2;
constexpr WEST = 3;

class Sokoban
{
public : 
    Sokoban();



    // string sLevel = 
    // "##########"
    // "#........#"
    // "#..p.....#"
    // "#........#"
    // "#........#"
    // "#........#"
    // "#........#"
    // "##########";


    string sLevel = 
        "####################"
        "#                  #"
        "#  $         $     #"
        "#      .       5   #"
        "#   3              #"
        "#       @     $    #"
        "#                  #"  
        "#      #     .     #"
        "# .     #          #"
        "####################";


    struct tuple
    {
        int x;
        int y;
    };

    tuple level_size = tuple(20,10);
    tuple block_size = tuple(10,10);
    tuple player_position;
    vector<tuple> goals;


    // struct levelSize
    // {
    //     int x = 20;
    //     int y = 10;
    // } levelSize;

    // struct blockSize
    // {
    //     int x = 10;
    //     int y = 10;

    // } blockSize;

    // struct PlayerPosition
    // {
    //     int x;
    //     int y;
    // };

    

    
    /**
     * virtual class of block
     */
    struct block 
    {
        block() // default constructro
        {
            
        }
        virtual void DrawSelf() // drw with fltk
        {
            
        }
        virtual bool push(const int from) // if the block can be push default yes
        {
            return true;
        }
        virtual void move() 
        {

        }
        virtual bool is_place_free()
        {

        }

    };

    vector <unique_ptr<block>> level_vector; //smart vect of the level

    struct Wall : public block
    {
        void DrawSelf() override
        {
            
        }
        bool push (const int from) override
        {
            return false;
        }

    };

    struct Player : public block
    {
        void DrawSelf() override
        {
            
        }
        bool push (const int from) override
        {
            return true;
        }

    };

    struct Heavy_block : public block 
    {
        void DrawSelf() override
        {
            
        }
        // faut trouver la solution ici doit retourner vrai ssi sa prochaine case est nullptr
        bool push (const int from) override 
        {
            return true;
            // switch(from)
            // {
            //     case NORTH: 
            //         if (level_vector[id()])
            // }
        }
        // virtual bool is_place_free()
        // {

        // }

    };

    struct Light_block : public block
    {
        void DrawSelf() override
        {
            
        }
        bool push (const int from) override
        {
            return true;
        }

    };

    struct Horizontal_block : public block
    {
        void DrawSelf() override
        {
            
        }
        bool push (const int from) override
        {
            return from == EAST || from == WEST;
        }

    };

    struct Vertical_block : public block
    {
        void DrawSelf() override
        {
            
        }
        bool push (const int from) override
        {
            return from == NORTH || from == SOUTH;
        }

    };

    struct Limited_block : public block
    {   
        Limited_block(int m)
        {
            remaining_moves = m;
        }

        void DrawSelf() override
        {
            // draw also remaining_moves on the block            
        }
        bool push (const int from) override
        {
            return remaining_moves > 0;
        }
        void move() override
        {
            remaining_moves--;
        }

        int remaining_moves;
    };







    void load_level()
    {
        //mettre a 0 les 2 vects
         for (int x = 0; x < level_size.x; x++)
         {
            for (int y=0; y< level_size.y; y++)
            {
                 switch (sLevel[y * level_size.x + x])
                 {
                    case '#':
                        level_vector.emplace_back(make_unique < Wall>());
                        break;
                    case '$':
                        level_vector.emplace_back(make_unique < Light_block>());
                        break;
                    case '@':
                        level_vector.emplace_back(make_unique < Player>());
                        player_position.x = x; player_position.y = y;
                        break;
                    case '-':
                        level_vector.emplace_back(make_unique < Horizontal_block>());
                        break;
                    case '|':
                        level_vector.emplace_back(make_unique < Vertical_block>());
                        break;
                    case '5':
                        level_vector.emplace_back(make_unique < Limited_block>(5));
                        break;
                    case '3':
                        level_vector.emplace_back(make_unique < Limited_block>(3));
                        break;
                    case '.':
                        level_vector.emplace_back(nullptr);
                        goals.push_back((x, y));
                        break;
                    case '+':
                        level_vector.emplace_back(make_unique < Heavy_block>());
                        break;
                    
                    default:
                        level_vector.emplace_back(nullptr);

                 }
            }
         }
    };

    void create()
    {
        load_level();
    };

    void update()
    {      
        auto id = [&](int x, int y) { return y * levelSize.x + x; }; // fct type id
        
        bool pushing = false;
        int push_direction = 0;
        if (GetKey("z").bpressed)
        {
            push_direction = NORTH;
            pushing = true;
        }
        if (GetKey("s").bpressed)
        {
            push_direction = SOUTH;
            pushing = true;
        }
        if (GetKey("q").bpressed)
        {
            push_direction = WEST;
            pushing = true;
        }
        if (GetKey("d").bpressed)
        {
            push_direction = EAST;
            pushing = true;
        }
        if (GetKey("r").bpressed)
        {
            load_level();
        }

         if (pushing)
         {
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

            if (allow_pushing) 
            {
                while(current_block != player_position) // swapping in the other way
                {
                     tuple source = current_block;
                     switch (push_direction)
                        {
                            case NORTH: source.y++; break;
                            case SOUTH: source.y--; break;
                            case EAST: source.x--; break;
                            case WEST: source.x++; break;
                        }
                    if (level_vector[id(source)] =! nullptr) level_vector[id(source)]->move();
                    swap(level_vector[id(source)], level_vector[id(current_block)]);

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
         }



        int goals_win;
        for (auto& g:goals)
        {
            if (level_vector[id(g)]) goals_win++;
        }


        for (int y=0; y < levelSize.y; y++)
        {
            for (int x=0; x < levelSize.x; x++)
            {
                auto &b=level_vector[id(x,y)];
                if (b)
                {
                    b->DrawSelf(); //draw tout les block
                }
            }   
        }
        // drawstring("goals :" + to_str(goals_win) + " / " + to_str(goals.size()))
    };
};

int main 
{
    return 0;
}



