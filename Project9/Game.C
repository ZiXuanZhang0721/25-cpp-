#include "Game.h"
#include <cstdlib>
#include <ctime>
#include "Tiger.h"
#include "Wolf.h"
#include "Rabbit.h"
#include "Grass.h"
#include "Item.h"
#include "Predator.h"
Game::Game() {
    gui.init();
    grassGrid.reserve(25 * 80);  // 只预留空间，不构造对象
    
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80; j++) {
            // ✅ 直接在 vector 中构造，无默认构造，无拷贝
            grassGrid.emplace_back(this, i, j);
            
        }
    }
    //Animals.reserve(25 * 80);
    cout<<"over";
}
void Game::update() {
    gui.clear(); //clear everything on the screen
    count++;
    int c = gui.get();
    updateItems(c, count);
    gui.redraw(); //draw things
}
void Game::updateItems(int c, size_t count) {
    // for (auto it = Animals.begin(); it != Animals.end(); ) {
    //     Animal* animal = *it;
        
    //     if (animal && animal->isAlive) {
    //         animal->update(c, count);
    //         ++it;
    //     } else{
    //         delete animal;
    //         animal = nullptr;
    //         it = Animals.erase(it);
    //     }
    // }
    for (auto it =grassGrid.begin();it != grassGrid.end();++it) (it) ->update (c,count);
}

void Game::paintAt(size_t r, size_t c, char x) {
    gui.paintat(r, c, x);
}

void Game::printMsg(size_t r, size_t c, const char* s) {
    gui.printMsg(r, c, s);
}

void Game::clearGrassAt(int row, int col) {
    int idx = row * 80 + col;
    if (idx >= 0 && idx < 2000) {
        grassGrid[idx].clear(); 
    }
}