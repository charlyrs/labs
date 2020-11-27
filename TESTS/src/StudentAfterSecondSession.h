#pragma once
#include "StudentAfterFirstSession.h"
#include "Student.h"

class StudentAfterSecondSession: public StudentAfterFirstSession {
private:
    StudentAfterSecondSession();
protected:
    int marksAfterSecondSession[5];
public:
    StudentAfterSecondSession(const StudentAfterFirstSession&, int*);
    StudentAfterSecondSession(char*, int, int, int*, int*);
    StudentAfterSecondSession (const StudentAfterSecondSession&);
    void SetSecondSessionMarks(int*);
    int* GetSecondSessionMarks();
    double AverageScore();
    friend std::ostream& operator << (std::ostream &out, StudentAfterSecondSession& a);
};



