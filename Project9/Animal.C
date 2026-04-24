#include "Animal.h"

Animal::Animal(Game* g,int x,int y):Item(g,x,y),livedays(0),isAlive(true){}

Animal::~Animal(){}