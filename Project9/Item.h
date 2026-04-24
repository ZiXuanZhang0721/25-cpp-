#ifndef ITEM_H
#define ITEM_H
#include <iostream>



class Game;

class Item {
public:
    size_t row;          
    size_t col;         
    size_t last;         
    Game* game;  
    bool isAlive;      
    
    Item(Game* g, int r, int c);
    virtual ~Item();
    
    virtual void update(int command, size_t count) = 0;
    virtual void print() = 0;
    
    size_t getRow() const { return row; }
    size_t getCol() const { return col; }
    
    
};

#endif