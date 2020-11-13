
#include "StudentAfterFirstSession.h"
#include <iostream>

StudentAfterFirstSession::StudentAfterFirstSession(char *_name, int _course, int _group, int* _marks)
:Student(_name,_course, _group){
    session = 1;
    for (int i=0; i<4; ++i){
        marksAfterFirstSession[i]=_marks[i];
    }

}
StudentAfterFirstSession::StudentAfterFirstSession(const Student& student, int* _marks)
:Student(student){
    session = 1;
    for (int i=0; i<4; ++i){
        marksAfterFirstSession[i]=_marks[i];
    }

}
StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& a) : Student(a) {
    session = 1;
    for (int i=0; i<4; ++i){
        marksAfterFirstSession[i]=a.marksAfterFirstSession[i];
    }

}


void StudentAfterFirstSession ::SetFirstSessionMarks(int *_marks) {

    for (int k=0; k<4;++k){
        marksAfterFirstSession[k]=_marks[k];
    }

}
int* StudentAfterFirstSession ::GetFirstSessionMarks() {
    return marksAfterFirstSession;
}
double StudentAfterFirstSession::AverageScore() {
    double sum=0;
    for (int i=0; i<4; ++i){
        sum+=marksAfterFirstSession[i];
    }
    return sum/4.0;
}
std::ostream& operator << (std::ostream &out, StudentAfterFirstSession& a){
    out << "Name: " << a.GetName() << '\n';
    out << "Course: " << a.GetCourse() << '\n';
    out << "Group: " << a.GetGroup() << '\n';
    out << "Identifier " << a.GetId() << '\n';
    out << "Record book number " << a.GetRecordBook() << '\n';
    out << "Marks after first session are ";
    for (int i=0; i<4; ++i){
       out << a.GetFirstSessionMarks()[i] << " ";
    }

    return out;

}