#ifndef _GAME_H_
#define _GAME_H_
#include <vector>
#include "Gui.h"
class Grass;
class Rabbit;
class Wolf;
class Tiger;
class Animal;
class Predator;
using namespace std;


class Game {
public:
    Gui gui;
    vector<Grass> grassGrid;
    // vector<Animal*> Animals;
    size_t count;
    bool flag=true;
    Game() ;
    ~Game() {gui.end();}
    void paintAt(size_t r, size_t c, char x);
    void printMsg(size_t r, size_t c, const char* s);
    void update();
    void updateItems(int c, size_t count);
    // const vector<Animal*>&  returnAnimals() const{
    //     return Animals;
    // }
    const vector<Grass>& returnGrasses() const {
        return grassGrid;
    }
    void clearGrassAt(int row, int col) ;
};
#endif
