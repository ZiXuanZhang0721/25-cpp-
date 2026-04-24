#ifndef WORLD_H
#define WORLD_H
#include "Group.h"
#include "Weather.h"

class World{
    Group** groups;
    size_t groupcount;
    Weather* W;

    public:
    World(size_t c);
    ~World();
    void DoSimulation();
};
#endif