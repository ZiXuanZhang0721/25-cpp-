#include "World.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

World::World(size_t c):groups(nullptr),groupcount(0),W(nullptr){
    groupcount =c;
    groups = new Group*[c];
    int people= 30;
    int startingID=1;
    for (size_t i=0;i<groupcount;i++){
        groups[i] = new Group(startingID,people);
        startingID+=people;
    }
    W = new Weather();
}


World::~World(){
    for (size_t i =0 ;i<groupcount;i++)
        delete groups[i];
    delete[] groups;
    delete[] W;
}


void World::DoSimulation(){
    for (size_t day =1;day<=30;day++){
        std::cout<<"Day "<<day<<": ";
        W -> UpdateWeather();
        int current = W ->Getweather();
        for (size_t i = 0;i<groupcount;i++){ 
            groups[i]->GroupDecision(current);
            std::cout << "Group " << (i + 1) << ": ";
            groups[i]->Report();
        }std::cout<<std::endl;
        if ((rand()%5+1)<=2){
            int cnt = rand()%groupcount;
            Group*newGroup = groups[cnt]->Split();
            if (newGroup != nullptr) {
                Group** newGroups = new Group*[groupcount + 1];
                for (size_t i = 0; i < groupcount; i++) {
                    newGroups[i] = groups[i];
                }
                newGroups[groupcount] = newGroup;
                delete[] groups;
                groups = newGroups;
                groupcount++;
            }
        }
    }
}