#ifndef RABBIT_H
#define RABBIT_H
#include "Animal.h"
#include "Grass.h"
#include <stdlib.h>
#include <ctime>
class Game;
class Rabbit :public Animal{
public:
    Rabbit(Game* game,int row,int col);
    ~Rabbit();
    void print();
    void update(int command, size_t count);
    void move();
    bool eat();
    void clear();
};

#endif