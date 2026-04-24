#include "Wolf.h"
#include "Game.h"
Wolf::Wolf(Game*g ,int x,int y):Predator(g,x,y){}
Wolf::~Wolf(){}
void Wolf::move(){
    int dx = rand() % 5 - 2; 
    int dy = rand() % 5 - 2;

    int newRow = row + dx;
    int newCol = col + dy;
    
    if (newRow >= 0 && newRow < 25 && newCol >= 0 && newCol < 80) {
        row = newRow;
        col = newCol;
    }
}

bool Wolf::eat(){
    // for (int i = -2; i<3; i++){
    //     for(int j =-2; j<3; j++){
    //         if (game->getRabbit(row+i,col+j)) {
    //             game->getRabbit(row+i,col+j)->clear();
    //             row +=i;col+=j;
    //             return true;
    //         }
    //     }
    // }
    return false;
}

void Wolf::clear(){
    isAlive=false;
}

void Wolf::print(){
    if ( row < 25 && col < 80) {
        game->paintAt(row, col, 'W');
    }
}

void Wolf::update(int command,size_t count){
    livedays++;
    if (livedays>3||!isAlive) return;
    eat();
    if (!eat()) move();
}