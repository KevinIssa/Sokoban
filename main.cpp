// g++ -std=c++11 main.cpp sokoban.cpp -o term -lfltk && ./term  
#include "main_window.h"





int main()
{   
    Sokoban soko;
    soko.init();




    MainWindow window{&soko};
    window.show();
    return Fl::run();
    return 0;
}

