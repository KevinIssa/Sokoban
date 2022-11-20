
// #include "sokoban.h"
// #include "case.h"
#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>

using namespace std;

class Player : public Case
{
    public:
        // Player(string name, char value, tup pos, Fl_Color col, const uchar* im): Case(name,value, pos, col, im){}
        Player(string name, char value, tup pos, Fl_Color col): Case(name,value, pos, col){}
        Player(string name, char value,tup pos, Fl_Color col, const char* path): name{name},value{value},repr{value}, position{pos}, color{col}, image{Fl_PNG_Image {path} .copy(size,size)}{}
        
};