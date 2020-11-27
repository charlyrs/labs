#pragma once
#include "Student.h"

class StudentAfterFirstSession: public Student {
private:
    StudentAfterFirstSession();
protected:
    int marksAfterFirstSession[4];

public:
    StudentAfterFirstSession(const Student&, int*);
    StudentAfterFirstSession(char*, int,int, int*);
    StudentAfterFirstSession(const StudentAfterFirstSession&);


    void SetFirstSessionMarks(int*);
    int* GetFirstSessionMarks();
    double AverageScore();
    friend std::ostream& operator << (std::ostream &out, StudentAfterFirstSession& a);
};





