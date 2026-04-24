#ifndef ANIMAL_H
#define ANIMAL_H
#include "Item.h"

class Animal:public Item{
public:
    int livedays;
    bool isAlive;
	Animal(Game* g,int row,int col);
    virtual void print() = 0;
    virtual void update(int command, size_t count) = 0;
    virtual ~Animal();
    virtual void move() = 0;
    virtual bool eat() = 0;
};

#endif
