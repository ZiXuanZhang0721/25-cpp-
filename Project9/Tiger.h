#ifndef TIGER_H
#define TIGER_H
#include "Predator.h"
#include "Rabbit.h"
#include "Wolf.h"
class Game;
class Tiger : public Predator{
public:
    Tiger(Game*,int,int);
    ~Tiger()=default;
    void move();
    bool eat();
    void clear();
    void print();
    void update(int,size_t);
};
#endif