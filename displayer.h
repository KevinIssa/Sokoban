#ifndef _DISPLAYER_
#define _DISPLAYER_

const int FREQ=60;

class Displayer 
{   
    private:
        Sokoban *soko;
        // int id(int x, int y){return y * 10 + x;}
        // tup reverse_id(int x){return tup{x%10, x/10};}
    public:
        Displayer(Sokoban *soko) : soko{soko}{}
        
        void draw() // cal FREQ/seq
        {   
            fl_draw_box(FL_FLAT_BOX, 0, 0, 500, 500, FL_WHITE);
            int i=0;
            for (auto &c:soko->get_level_c())
            {
                if (c.get_value()!=' ' ){c.get_image()->draw(soko->reverse_id(i).x*c.get_size(), soko->reverse_id(i).y*c.get_size());}
                i++;
            }
            for (auto &g:soko->get_goals_v())
            {   
                if (soko->get_level_c()[soko->id(g.x, g.y)].get_repr()=='.'||soko->get_level_c()[soko->id(g.x, g.y)].get_repr()==' ')
                {  
                    Fl_Image *im =Fl_PNG_Image {"pika.png"} .copy(50,50);
                    im->draw(g.x*50, g.y*50);
                }
            }

        }
};


#endif

