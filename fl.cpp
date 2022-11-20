#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <vector>
using namespace std;


struct tup
{
    int x,y;
};


class MainWindow : public Fl_Window 
{       

    public:
        MainWindow() : Fl_Window (100,100,500,500,"tot") 
        {
        resizable(this);
        }
        void draw() override ;   
        
        
        
        
        int handle(int event) override {
        switch (event) {
        case FL_KEYDOWN:
            switch(Fl::event_key())
            {
                case 'z':
                    if(soko.check_move(current_pos, NORTH)){soko.play_move(current_pos, NORTH)};
                    break;
                case 's':
                    if(soko.check_move(current_pos, SOUTH)){soko.play_move(current_pos, SOUTH)};
                    break;
                case 'q':
                    if(soko.check_move(current_pos, WEST)){soko.play_move(current_pos, WEST)};
                    break;
                case 'd':
                    if(soko.check_move(current_pos, EAST)){soko.play_move(current_pos, EAST)};
                    break;
                case 'r':
                    printf("RESET LVL ...");
                    level_c.clear();
                    for (auto&c:original_level)
                    {
                        level_c.push_back(c);
                    }
                    // level_c = original_level;
                    pos_player.x=original_pos.x;
                    pos_player.y=original_pos.y;
                    break;
                case 'p':
                    printf("GAME OVER !!!\n");break;

            }

            return 1;
        default:
            return 0;
        }
        return 0;
    }
};




int main()
{
    MainWindow window;
    window.draw();
    window.show();
    
    return Fl::run();
}


void MainWindow::draw() override 
        {
            vector<tup> ve;
            Fl_Window::draw();
            fl_draw_box(FL_FLAT_BOX, 0, 0, 50, 50, FL_GREEN);
        
            int c=0;
            int d;
            for (int i=0;i<10;i++)
            {
                for (int j=0;j<10;j++)
                {   
                    d=(i+j)%2;
                    ve.push_back(tup{i,j});
                }
            }
            for (auto &g:ve)
            {   
                int d = (g.x+g.y)%2;
                if (d){fl_draw_box(FL_FLAT_BOX, g.x*50, g.y*50, 50, 50, FL_GREEN);}
                else {fl_draw_box(FL_FLAT_BOX, g.x*50, g.y*50, 50, 50, FL_BLACK);}

            }

        }