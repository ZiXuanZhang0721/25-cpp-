#include "Tiger.h"
#include "Game.h"
Tiger::Tiger(Game*g ,int x,int y):Predator(g,x,y){}

void Tiger::move(){
    int dx = rand() % 7 - 3; 
    int dy = rand() % 7 - 3;

    int newRow = row + dx;
    int newCol = col + dy;
    
    if (newRow >= 0 && newRow < 25 && newCol >= 0 && newCol < 80) {
        row = newRow;
        col = newCol;
    }
}

bool Tiger::eat(){
    // for (int i = -3; i<4; i++){
    //     for(int j =-3; j<4; j++){
    //         if (game->getRabbit(row+i,col+j)) {
    //             game->getRabbit(row+i,col+j)->clear();
    //             row +=i;col+=j;
    //             return true;
    //         }
    //         if (game->getWolf(row+i,col+j)){
    //             if (rand()%3==0){
    //             game->getWolf(row+i,col+j)->clear();
    //             row +=i;col+=j;
    //             return true;                    
    //             }
    //         }
    //     }
    // }
    return false;
}

void Tiger::clear(){
    isAlive=false;
}

void Tiger::print(){
    if ( row < 25 && col < 80) {
        game->paintAt(row, col, 'T');
    }
}

void Tiger::update(int command,size_t count){
    livedays++;
    if (livedays>3||!isAlive) return;
    eat();
    if (!eat()) move();
}