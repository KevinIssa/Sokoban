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

