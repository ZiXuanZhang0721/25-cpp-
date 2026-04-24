#include "StudentVector.h"
#include <iostream>

using namespace std;

StudentVector::StudentVector() { size = 30; len = 0; p = new Student*[size];}
void StudentVector::Clear() {
    len = 0;
}
StudentVector::~StudentVector() {
    delete[] p;
    p = nullptr;
}
void StudentVector::Push(Student* student) {
    if (len == size) {
        size = size * 2;
        Student** new_p = new Student*[size];
        for (size_t i = 0; i < len; i++) {
            new_p[i] = p[i];
        }
        delete[] p;
        p = new_p;
    }
    p[len++] = student;
}
Student*& StudentVector::operator[](size_t i) {
    return p[i];
}