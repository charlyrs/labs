#include "Student.h"
#include <iostream>
int Student::quantity=0 ;

Student::Student(char* _name, int _course, int _group){
    session = 0;
    int size = strlen(_name);
    name = new char[size+1];
    for (int k=0; k<size; ++k){
        name[k]=_name[k];
        if (k==size-1) name[k+1]= '\0';
    }
    course=_course;
    group=_group;

    quantity++;
    identifier=name[0]+std::to_string(quantity);
    recordBook=std::to_string(course) + "0" + std::to_string(group)+ "0" + std::to_string(quantity) ;


}
Student::Student(const Student &a) {
    session = 0;
    int size = strlen(a.name);
    name = new char[size+1];
    for (int k=0; k<size; ++k){
        name[k]=a.name[k];
        if (k==size-1) name[k+1]= '\0';
    }
    course=a.course;
    group=a.group;
    quantity++;
    identifier=name[0]+std::to_string(quantity);
    recordBook=a.recordBook;

}

Student::~Student(){

    delete[] name;
}
std::string Student::GetId() {
    return identifier;
}
std::string Student::GetRecordBook() {
    return recordBook;
}
char* Student::GetName() {
    return name;
}
int Student::GetCourse() {
    return course;
}
int Student::GetGroup() {
    return group;
}
void Student::SetName(char *newname) {
    int size = strlen(newname);
    name = new char[size+1];  
    for (int k=0; k<size; ++k){
        name[k]=newname[k];
        if (k==size-1) name[k+1]= '\0';
    }
}
void Student::SetCourse(int newcourse) {
    course=newcourse;
}
void Student::SetGroup(int newgroup) {
    group=newgroup;
}
std::ostream& operator << (std::ostream &out, Student& a){
    out << "Name: " << a.name << '\n';
    out << "Course: " << a.course << '\n';
    out << "Group: " << a.group << '\n';
    out << "Identifier " << a.GetId() << '\n';
    out << "Record book number " << a.GetRecordBook() << '\n';

    return out;

}
double Student::AverageScore() {
    return 0;
}
int Student::GetSession() {
    return session;
}