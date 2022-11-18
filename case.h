#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
// #import "sokoban.h"
using namespace std;

class Case
{
    private:
        string name;
        char repr;
        char value;

    public:
    // Case(string name, const char repr);
        Case(string name, char value): name{name},value{value},repr{value}{}
        Case(string name, char value, char repr): name{name},value{value},repr{repr}{}

        string get_name(){return name;}
        const char get_repr(){return repr;}
        // void draw(){printf("%d",get_repr());}
        const char get_value(){return value;}
        const char draw(){return repr;}
        void set_repr(char r){repr=r;}
        void set_value(char r){value=r;}
};