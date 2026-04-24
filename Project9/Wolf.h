#ifndef WOLF_H
#define WOLF_H
#include "Predator.h"
#include "Rabbit.h"

class Wolf :public Predator{
public:
    Wolf(Game*,int,int);
    ~Wolf();
    void move();
    bool eat();
    void clear();
    void print();
    void update(int,size_t);
};
#endif