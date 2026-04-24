#include "Item.h"


Item::Item(Game* g, int r, int c) 
    : game(g), row(r), col(c), last(0) {}

Item::~Item() {}