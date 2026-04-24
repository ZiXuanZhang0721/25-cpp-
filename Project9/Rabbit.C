#include <stdlib.h>
#include <ctime>
#include "Rabbit.h"
#include "Game.h"
Rabbit::Rabbit(Game*g,int row,int col):Animal(g,row,col){}
Rabbit::~Rabbit() = default;
void Rabbit::print() {
    if (row >= 0 && row < 25 && col >= 0 && col < 80) {
        game->paintAt(row, col, 'R');
    }
}
void Rabbit::update(int command, size_t count){
    livedays++;
    if (livedays > 2 || !isAlive) {
        return;
    }move();
    eat();
    
}
bool Rabbit::eat(){
    const vector<Grass>& grasses = game->returnGrasses();
    Grass grassnow= grasses[row*80+col];
    if (grassnow.growth==3) {
        livedays =0;
        game->clearGrassAt(row,col);
        return true;
    }
    else return false;
}
void Rabbit::move() {
    int dx = rand() % 3 - 1; 
    int dy = rand() % 3 - 1;

    int newRow = row + dx;
    int newCol = col + dy;
    
    if ( newRow < 25 && newCol < 80) {
        row = newRow;
        col = newCol;
    }
}

void Rabbit::clear(){
    isAlive = false;
}