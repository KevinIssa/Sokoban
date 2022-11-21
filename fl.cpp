// g++ -std=c++11 fl.cpp -o fl -lfltk && ./fl 
// #include <FL.H>
// #include <fL_draw.H>
// #include <FL_Double_Window.H>
// #include <FL_Box.H>
// #include <FL_PNG_Image.H>


#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Button.H>




#include <vector>
// #include <opencv2/core/mat.hpp>
using namespace std;


struct tup
{
    int x,y;
};


class MainWindow : public Fl_Window 
{       
    Fl_Window *win;
    Fl_Button *reset;


    public:
        MainWindow() : Fl_Window (100,100,650,500,"XXX") 
        
        // MainWindow()  
        { 
            win = new Fl_Window (500,0,150,550,"tot");
            win->begin();
            reset = new Fl_Button(80/2, 10, 80, 25, "Beep");
            // Fl_Button *b1 = new Fl_Button(20, 10, 80, 25, "Beep");
            win->end();
    // show();



        resizable(this);
        }
        // void draw() override ;   
        
void draw() override 
        {
            Fl_Window::draw();
            vector<tup> ve;int c=0;int d;for (int i=0;i<10;i++){for (int j=0;j<10;j++){   d=(i+j)%2;ve.push_back(tup{i,j});}}for (auto &g:ve){   int d = (g.x+g.y)%2;if (d){fl_draw_box(FL_FLAT_BOX, g.x*50, g.y*50, 50, 50, FL_GREEN);}else {fl_draw_box(FL_FLAT_BOX, g.x*50, g.y*50, 50, 50, FL_BLACK);}}
            const char* path2 = "pokeball.jpeg";

            Fl_PNG_Image im {"Pok1.png"};
            Fl_Image *im2=im.copy(50,50);
            im2->draw(0,0);



            // const char* path = "Pok1.png";
            // im.draw(0,0, 250, 250);
            // im.h(50);im.w(50);


            // Fl_JPEG_Image im (path2);
            
            // Mat image = imread("Pok1.png", 1);
            // unsigned char *ptr_source = image.data;
            // unsigned char *buf;

            // Fl_Draw_Image_Cb("pokeball.jpeg", 50, 50, -1 buf);
            // fl_draw_image(im, 10,10, 500, 500);

            // fl_draw_image((const unsigned  char *)("poke"), 10,10, 500, 500);
        }
        
};




int main()
{
    MainWindow window;
    // MainWindow *window = new MainWindow();

    // Fl_Window *window = new Fl_Window(320,65);

    // window->begin();
    // Fl_Button *b1 = new Fl_Button(20, 10, 80, 25, "Beep");
    // window->end();
    // window.draw();
    // Fl::visual(FL_RGB);
    window.show();
    
    return Fl::run();
}


            // fl_draw_box(FL_FLAT_BOX, 0, 0, 50, 50, FL_GREEN);