
#include "StudentAfterSecondSession.h"
#include <iostream>
StudentAfterSecondSession::StudentAfterSecondSession(char *name, int course, int group, int marks1[4], int* marks2)
:StudentAfterFirstSession(name, course, group, marks1){

    for (int i=0; i<5; ++i){
        marksAfterSecondSession[i]=marks2[i];
    }


}
StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterFirstSession & stud, int* marks2)
:StudentAfterFirstSession(stud){

    for (int i=0; i<5; ++i){
        marksAfterSecondSession[i]=marks2[i];
    }

}
StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession&a) : StudentAfterFirstSession(a) {

    for (int i=0; i<5; ++i){
        marksAfterSecondSession[i]=a.marksAfterSecondSession[i];
    }


}

void StudentAfterSecondSession::SetSecondSessionMarks(int *m) {

    for (int i=0; i<5; ++i){
        marksAfterSecondSession[i]=m[i];
    }


}
int* StudentAfterSecondSession::GetSecondSessionMarks() {
    return marksAfterSecondSession;
}
double StudentAfterSecondSession::AverageScore() {
    double sum=0;
    for ( int i=0; i <4; ++i){
        sum+= GetFirstSessionMarks()[i];
    }
    for (int i=0; i<5; ++i){
        sum+=marksAfterSecondSession[i];
    }
    return sum/9.0;
}
std::ostream& operator << (std::ostream &out, StudentAfterSecondSession& a){
    out << "Name: " << a.GetName() << '\n';
    out << "Course: " << a.GetCourse() << '\n';
    out << "Group: " << a.GetGroup() << '\n';
    out << "Identifier " << a.GetId() << '\n';
    out << "Record book number " << a.GetRecordBook() << '\n';
    out << "Marks after the first session are ";
    for (int i=0; i<4; ++i){
        out << a.GetFirstSessionMarks()[i] << " ";
    }
    out << "\nMarks after the second session are ";
    for (int i=0; i<5; ++i){
        out << a.marksAfterSecondSession[i] << " ";
    }
    return out;
}