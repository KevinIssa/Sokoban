

class Level
{   string level_s;
    tup size;
    public :
        Level(string lvl, tup si):level_s{lvl},size{si}{}
        string get_level_s(){return level_s;}
        tup get_size(){return size;}
};