#ifndef _GROUP_H_
#define _GROUP_H_
#include <memory>
#include "Student.h"
#include "StudentVector.h"
#include <cstddef>
#include <iostream>

using namespace std;
class Group {
    StudentVector students;
    size_t count;
    int* decisions;
    size_t playCount;
public:
    Group(int s, size_t c);
    void GroupDecision(int w);
    //void Report();
    Group* Split();
    ~Group();
    friend ostream&operator<<(ostream &os, const Group &g);
    Group& operator+=(Group& g);

};
#endif
