#ifndef _DISPLAYER_
#define _DISPLAYER_
#include "button.cpp"
const int FREQ=60;

class Displayer 
{   
    private:
        Sokoban *soko;
        //Button button;
        // int id(int x, int y){return y * 10 + x;}
        // tup reverse_id(int x){return tup{x%10, x/10};}
    public:
        Displayer(Sokoban *soko) : soko{soko}{}
        void draw(); // cal FREQ/seq

};


#endif

