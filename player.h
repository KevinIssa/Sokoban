#include<string>
#include <iostream>
#include <vector>
#include<time.h>
#include <unistd.h>
using namespace std;

class Player : public Case
{
    public:
        Player(string name, char value): Case(name,value){}

};