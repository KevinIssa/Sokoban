// g++ -std=c++11 fl.cpp -o fl -lfltk && ./fl 
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <vector>
// #include <opencv2/core/mat.hpp>
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
        // void draw() override ;   
        
void draw() override 
        {
            Fl_Window::draw();
            vector<tup> ve;int c=0;int d;for (int i=0;i<10;i++){for (int j=0;j<10;j++){   d=(i+j)%2;ve.push_back(tup{i,j});}}for (auto &g:ve){   int d = (g.x+g.y)%2;if (d){fl_draw_box(FL_FLAT_BOX, g.x*50, g.y*50, 50, 50, FL_GREEN);}else {fl_draw_box(FL_FLAT_BOX, g.x*50, g.y*50, 50, 50, FL_BLACK);}}
            // Mat image = imread("Pok1.png", 1);
            // unsigned char *ptr_source = image.data;
            // unsigned char *buf;

            // Fl_Draw_Image_Cb("pokeball.jpeg", 50, 50, -1 buf);
            // fl_draw_image(buf, 10,10, 500, 500);

            // fl_draw_image((const unsigned  char *)("poke"), 10,10, 500, 500);
        }
        
};




int main()
{
    MainWindow window;
    window.draw();
    Fl::visual(FL_RGB);
    window.show();
    
    return Fl::run();
}


            // fl_draw_box(FL_FLAT_BOX, 0, 0, 50, 50, FL_GREEN);