#include <ncurses.h>
#include "Gui.h"
#include <sys/time.h>
#include <stdlib.h>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <cstddef>
#include "Game.h"
#include "Tiger.h"
#include "Wolf.h"
#include "Rabbit.h"
#include "Grass.h"
#include "Item.h"
#include "Predator.h"

int main(int argc,char* argv[]){

    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <rabbit_count> <wolf_count> <tiger_count>" << std::endl;
        return 1; 
    }
    // int rnum = atoi(argv[1]);
    // int wnum = atoi(argv[2]);
    // int tnum = atoi(argv[3]);
    srand(time(0));
    struct timeval time_now;
    // for (int i =0;i<rnum;i++){
    //     int x = rand()%25;
    //     int y = rand()%80;
    //     if (!game.Animals[80*x+y]) game.Animals[80*x+y] = new Rabbit(&game,x,y);
    // }
    // for (int i =0;i<wnum;i++){
    //     int x = rand()%25;
    //     int y = rand()%80;
    //     if (!game.Animals[80*x+y]) game.Animals[80*x+y] = new Wolf(&game,x,y);
    // }
    // for (int i =0;i<tnum;i++){
    //     int x = rand()%25;
    //     int y = rand()%80;
    //     if (!game.Animals[80*x+y]) game.Animals[80*x+y] = new Tiger(&game,x,y);
    // }
    gettimeofday(&time_now, NULL);
    Game game;
    time_t oldTime = (time_now.tv_sec*1000)+(time_now.tv_usec/1000);
    time_t currentTime =  oldTime;
    while (true) {
        gettimeofday(&time_now, NULL);
        currentTime =(time_now.tv_sec*1000)+(time_now.tv_usec/1000);
        if (currentTime - oldTime < 60) {usleep(22);continue;}
        game.update();
        oldTime = currentTime;
    }
    

    return 0;
}