#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include "Student.h"
class Group{
    Student**students;
    size_t count;
    int *Decisions;

    public:
      Group(int startingID,size_t c);
      ~Group();
      void GroupDecision(int weather);
      void Report();
      Group*Split();
      
        
};
#endif