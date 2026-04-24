#include "Group.h"
#include <iostream>

using namespace std;
Group::Group(int s, size_t c) {
    count = c;
    decisions = new int[count]; 
    playCount = 0;
    for (size_t i = 0; i < count; i++) {
        students.Push(new Student(s+i)); 
    }
}
void Group::GroupDecision(int w) {
    int d = 0;
    playCount = 0;
    for (size_t i = 0; i < count; i++) {
        d = students[i]->MakeDecision(w);
        if (d == 0) {
            decisions[playCount] = students[i]->GetID();
            playCount++;
        }
    }
    return;
}

ostream& operator<<(ostream &os, const Group &g) {
    os << g.playCount << " play, "<< g.count - g.playCount << " not play\n";
    os << "    Play ID: ";
    for (size_t i = 0; i < g.playCount&& i < g.count; i++) {
        os << g.decisions[i] << " "; }
    os << endl;
    return os;
}
Group* Group::Split() {
    if (count < 10) return NULL;
    size_t lc = count/2;
    size_t rc = count - lc;
    count = lc;
    Group* temp = new Group(0, rc);
    for (size_t i = 0; i < rc; i++) {
        delete temp->students[i];
        temp->students[i] = nullptr; 
	temp->students[i] = students[lc+i];
    }
    return temp;
}

Group::~Group() {
    for (size_t i = 0; i < count; i++) {
        if (students[i] != nullptr) {  
            delete students[i];
            students[i] = nullptr; 
        }
    }
    delete [] decisions;
}
Group& Group::operator+=(Group& g) {
    int* new_decisions = new int[count + g.count];
    
    for (size_t i = 0; i < count; i++) {
        new_decisions[i] = decisions[i];
    }
    
    delete[] decisions;
    decisions = new_decisions;
    
    for (size_t i = 0; i < g.count; i++) {
        students.Push(g.students[i]);
    }
    count += g.count;
    students.len = count;
    
    g.students.len = 0;    
    g.count = 0;
    delete [] g.decisions;
    g.decisions = nullptr;  
    
    return *this;
}