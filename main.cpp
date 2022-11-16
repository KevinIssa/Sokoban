#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>

 // for the GetKey function, have to find an alternative with fltk
// levels : https://github.com/deepmind/boxoban-levels

using namespace std;
const int windowWidth = 500;
const int windowHeight = 500;
const double refreshPerSecond = 60;

#define NORTH = 0;
#define EAST = 1;
#define SOUTH = 2;
#define WEST = 3;

struct tupe
    {
        int x;
        int y;
    };

class Rectangle {
  tupe center;
  int w, h;
  Fl_Color fillColor, frameColor;

 public:
  Rectangle(tupe center);
  void draw();
  void setFillColor(Fl_Color newFillColor);
  Fl_Color getFillColor() {
    return fillColor;
  }
  void setFrameColor(Fl_Color newFrameColor);
  Fl_Color getFrameColor() {
    return frameColor;
  }
  int getWidth() {
    return w;
  }
  int getHeight() {
    return h;
  }
};

Rectangle::Rectangle(tupe center):
  center{center}{}

void Rectangle::draw() {
  fl_draw_box(FL_FLAT_BOX, center.x-10/2, center.y-10/2, 10, 10, fillColor);
  fl_draw_box(FL_BORDER_FRAME, center.x-10/2, center.y-10/2, 10, 10, frameColor);
}

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

    tupe level_size{20,10};
    tupe block_size{10,10};
    tupe player_position;
    vector<tupe> goals;


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
        Rectangle r;
        block(tupe center, int w, int h) // default constructro
        {
            r{center};
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
        r.setFillColor(FL_RED);
        r.draw()
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
        r.setFillColor(FL_BLUE);
        r.draw()
        }
        bool push (const int from) override
        {
            return true;
        }

    };

    struct Heavy_block : public block // give command and resolve inside your simulation
                                      // modify your valid move check to see if the place location + 1 is block and location + 2 is empty
    {
        void DrawSelf() override
        {
        r.setFillColor(FL_YELLOW);
        r.draw() 
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
        r.setFillColor(FL_WHITE);
        r.draw()
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
                        level_vector.emplace_back(make_unique < Wall>(tuple(x,y),block_size.x,block_size.y));
                        break;
                    case '$':
                        level_vector.emplace_back(make_unique < Light_block>(tuple(x,y),block_size.x,block_size.y));
                        break;
                    case '@':
                        level_vector.emplace_back(make_unique < Player>(tuple(x,y),block_size.x,block_size.y));
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
                        level_vector.emplace_back(make_unique < Heavy_block>(tuple(x,y),block_size.x,block_size.y));
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

class Canvas(){
    Sokoban soko;
    initialise();
    void draw();

}

void Canvas::initalise(){
    soko.create();
}

void Canvas::draw(){
    for (int x=0; y < soko.levelSize.x; x++)
        {
            for (int y=0; x < soko.levelSize.y; y++)
            {
                auto &b=soko.level_vector[id(x,y)];
                if (b)
                {
                    b->DrawSelf(); //draw tout les block
                }
            }   
        }
}

class MainWindow : public Fl_Window {
    Canvas canvas;

 public:
  MainWindow() : Fl_Window(500, 500, windowWidth, windowHeight, "SOKOBAN") {
    Fl::add_timeout(1.0/refreshPerSecond, Timer_CB, this);
    resizable(this);
  }
  void draw() override {
    Fl_Window::draw();
    canvas.draw();
  }
  int handle(int event) override {
    switch (event) {
      case FL_MOVE:
        canvas.mouseMove(Point{Fl::event_x(), Fl::event_y()});
        return 1;
      case FL_PUSH:
        canvas.mouseClick(Point{Fl::event_x(), Fl::event_y()});
        return 1;
      case FL_KEYDOWN:
        canvas.keyPressed(Fl::event_key());
        return 1;
      default:
        return 0;
    }
    return 0;
  }
  static void Timer_CB(void *userdata) {
    MainWindow *o = static_cast<MainWindow*>(userdata);
    o->redraw();
    Fl::repeat_timeout(1.0/refreshPerSecond, Timer_CB, userdata);
  }
};

int main(int argc, char *argv[]) {
  MainWindow window;
  window.show(argc, argv);
  return Fl::run();
}




