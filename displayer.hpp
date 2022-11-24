#ifndef _DISPLAYER_
#define _DISPLAYER_
const int FREQ=60;
#include "sokoban.hpp"

class Displayer 
{   
    private:
        Sokoban *soko;
        // int id(int x, int y){return y * 10 + x;}
        // tup reverse_id(int x){return tup{x%10, x/10};}
    public:
        Displayer(Sokoban *soko) : soko{soko}{}
        ~Displayer()=default;
        void draw(); // cal FREQ/seq

};


#endif

