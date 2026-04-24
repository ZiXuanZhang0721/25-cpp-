#include <iostream>
#include "Student.h"
#include "Decision.h"
#include <cstdlib>    
#include <ctime> 
using namespace std;


    

Student::Student(int k):ID(k){
    double p = 0.1 + (rand()%90)/100.0;
    decision = new Decision(p);
}

Student::~Student(){
    delete decision;
}

int Student::MakeDecision(int weather) {
    return decision->MakeDecision(weather); 
}

int Student::GetID(){
    return ID;
}