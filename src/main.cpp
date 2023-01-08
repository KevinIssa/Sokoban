#include "game_window.hpp"

int main()
{   
    Sokoban soko;
    soko.init();
    Game_window soko_w{&soko};
    soko_w.show();
    return Fl::run();
}

