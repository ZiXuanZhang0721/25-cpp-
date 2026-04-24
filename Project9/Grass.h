#ifndef GRASS_H
#define GRASS_H
#include "Item.h"
class Game;

class Grass : public Item{
public:
    int growth;

    Grass() : Item(nullptr, 0, 0), growth(0) {}
    Grass(Game*,int,int);
    void grow();
    void update(int command, size_t count);
    void print();    
    void clear();

};
#endif