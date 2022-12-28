#ifndef _DISPLAYER_
#define _DISPLAYER_
const int FREQ=60;
#include "sokoban.hpp"

class Displayer 
{   
    private:
        Sokoban *soko;
       
    public:
        Displayer(Sokoban *soko) : soko{soko}{}
        ~Displayer()=default;
        void draw(); // cal FREQ/seq

};


#endif

