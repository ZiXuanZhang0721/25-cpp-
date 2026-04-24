
#ifndef STUDENT_H
#define STUDENT_H
class Decision;
class Student{
    int ID;
    Decision* decision;

    public:
      Student(int k);
      ~Student();
      int MakeDecision(int Weather);
      int GetID();
};
#endif