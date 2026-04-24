#include "World.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(NULL));
    World w(20);
    w.DoSimulation();
}