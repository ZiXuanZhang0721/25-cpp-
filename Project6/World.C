#include <iostream>
#include <cstdlib>
#include "World.h"

using namespace std;

World::World(size_t c) {
    count = size = c;
    groups = new Group*[count];
    for (size_t i = 0; i < count; i++) {
        groups[i] = new Group(30*i, 30);
    }
    weather = new Weather();
        std::cout << "World created with " << count << " groups" << std::endl;
}

World::~World() {
    for (size_t i = 0; i < count; i++) {
        if (groups[i] != nullptr) {
            delete groups[i];
            groups[i] = nullptr;
        }
    }
    
    delete[] groups;
    groups = nullptr;
    
    delete weather;
    weather = nullptr;
}
void World::DoSimulation() {
    for (size_t j = 0; j < 30; j++) {
        weather->UpdateWeather();
        int w = weather->GetWeather();
        HandleGroupSplit();
        HandleGroupMerge();
        cout << "Day " << j+1 << ":\n";
        for (size_t i = 0; i < count; i++) {
            groups[i]->GroupDecision(w);
            cout << "Groups " << i+1 << ": ";
            cout << *groups[i] << endl;
        }
    }
}

void World::HandleGroupSplit() {
    if (rand()%5 > 0) return;
    int dice = rand() % count;
    Group* temp = groups[dice]->Split();
    if (temp == NULL) return;

    if (count == size) {
	    size *= 2;
        Group** temp1 = new Group*[size];
        for (size_t i = 0; i < count; i++) temp1[i] = groups[i];
        delete [] groups;
        groups = temp1;
    
    }
    groups[count++] = temp;
    
}

void World::HandleGroupMerge() {
    if (count <= 1) return; 
    if (rand() % 5 > 0) return;
    
    size_t index1 = rand() % count;
    size_t index2;
    do {
        index2 = rand() % count;
    } while (index1 == index2);
    
    *groups[index1] += *groups[index2];
    
    delete groups[index2];
    groups[index2] = nullptr; 
    
    groups[index2] = groups[count-1];
    groups[count-1] = nullptr; 
    count--;
    
}