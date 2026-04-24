#include "Group.h"
#include <iostream>
using namespace std;


Group::Group(int startingID,size_t c):count(c){
    students = new Student *[c];
    Decisions = new int[c];
    for (size_t i = 0;i<c;i++){
        students[i] = new Student(startingID+i);
    }
}

Group::~Group() {
    for (size_t i = 0; i < count; i++) {
        delete students[i]; 
    }
    delete[] students;     
    delete[] Decisions;    
}


void Group::GroupDecision(int weather){
    for (size_t i =0;i<count;i++){
        Decisions[i]= students[i]->MakeDecision(weather);
    }
}

void Group::Report(){
    int num =0;
    for (size_t i=0;i<count;i++){
        if (Decisions[i] == 1) num++;
    }
    int nnum = count-num;
    cout<<"Play: "<<num<<",not play: "<<nnum<<endl;
    cout<<"  ID to play:";
    for (size_t i=0;i<count;i++){
        if (Decisions[i] == 1) cout<<students[i]->GetID()<<" "; 
    }
    cout<<endl;
}

Group*Group::Split(){
    if(count<10){
        return nullptr;
    }
    else{
        size_t cnt1 = count/2;
        size_t cnt2 = count - cnt1;
        int startingID = students[cnt1]->GetID();
    Group* newGroup = new Group(startingID, cnt2);
    
  
    count = cnt1;
    
    return newGroup;

    }
}
