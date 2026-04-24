#include "Grass.h"
#include "Game.h"

Grass::Grass(Game*g ,int x,int y):Item(g,x,y),growth(3){}
void Grass::grow(){
    if (growth<3) growth++;
}



void Grass::update(int command, size_t count){
    grow();
}


void Grass::print() {
    switch (growth) {
        case 0: 
            game->paintAt(row, col, ' '); 
            break;
        case 1: 
            game->paintAt(row, col, '.'); 
            break;
        case 2: 
            game->paintAt(row, col, ':'); 
            break;
        case 3: 
            game->paintAt(row, col, '*');  
            break;
        default: 
            game->paintAt(row, col, ' ');  
    }
}

void Grass::clear(){
    growth = 0;
}