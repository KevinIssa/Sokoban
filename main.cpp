// g++ -std=c++11 main.cpp sokoban.cpp -o term -lfltk && ./term  
#include "main_window.h"





int main()
{   
    MainWindow window;
    window.show();
    return Fl::run();
}

