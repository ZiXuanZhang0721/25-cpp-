#include "Student.h"
#include <cstdlib>


Student::Student(int x) : ID (x) {
    decision = new Decision(0.1 + rand() % 90 / 100.0);
}


int Student::MakeDecision(int weather) {
    if (decision == nullptr) {
        return 1;
    }
    return decision->MakeDecision(weather);
}
Student::~Student() {
    delete decision;
}

int Student::GetID() {return ID;}
