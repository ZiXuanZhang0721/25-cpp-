#ifndef PREDATOR_H
#define PREDATOR_H
#include "Animal.h"
class Predator: public Animal{
public:
    Predator(Game*,int,int);
    virtual ~Predator()=0;
    virtual void move()=0;
    virtual bool eat()=0;
    virtual void print()=0;
    virtual void update(int,size_t)=0;
};
#endif