#ifndef STUDENT_VECTOR_H_
#define STUDENT_VECTOR_H_
#include <cstddef>
#include "Student.h"
#include <memory.h>
using namespace std;

class StudentVector{
    Student** p;
    size_t size;
    
public:
    size_t len;
    StudentVector();
    ~StudentVector();
    void Clear();
    void Push(Student*);
    Student*& operator[](size_t i) ;
};
#endif
