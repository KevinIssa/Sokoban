#ifndef _LEVEL_H
#define _LEVEL_H


class Level
{   string level_s;
    Vector2D size;
    public :
        Level(string lvl, Vector2D size):level_s{lvl},size{size}{}
        string get_level_s(){return level_s;}
        Vector2D get_size(){return size;}
};

#endif