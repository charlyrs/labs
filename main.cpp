#include <iostream>
#include "Student.h"
#include "StudentAfterFirstSession.h"
#include "StudentAfterSecondSession.h"
#include <vector>

double AverageScoreForAllStudents(std::vector<Student*> students){
    double sum=0;
    for (auto& person : students) {
        sum+=person->AverageScore();
    }
    return (double)sum/students.size();
}
double AverageScoreForGroup (std::vector<Student*> students, int course, int group){
    double sum=0;
    double count=0;
    for (auto& person : students){
        if(person->GetCourse()==course && person->GetGroup()==group){
            sum+=person->AverageScore();
            count++;
        }
    }
    return sum/count;
}


int main() {
    Student student("Liliya Khomyakova",1,4);
    Student student1("Vova Bullatov", 1, 3);
    Student student2("Georgiy Razmislovich", 1, 3);
    std::cout << student1 << '\n';
    student1.SetGroup(4);
    std::cout<<student1.GetGroup()<<'\n';
    student1.SetName("Vladimir Bullatov");
    std::cout<<student2.GetId() << " " << student2.GetRecordBook() << '\n';
    int k[4]={9,9,9,9};
    int n[4]={9,9,10,9};
    int l[5]={10,9,9,6,6};
    int v[5]={10,9,9,10,10};
    StudentAfterFirstSession student3(student,k);
    std::cout << student3 << '\n';

    int* s= student3.GetFirstSessionMarks();
    std::cout <<s[0] << '\n';
    student3.SetFirstSessionMarks(n);
    std::cout << student3.GetFirstSessionMarks()[2] << '\n';
    StudentAfterFirstSession student4(student2,n);

    StudentAfterSecondSession student5(student4,l);
    StudentAfterSecondSession student6(student3,v);
    StudentAfterSecondSession student7(student3,v);

    std::cout<< student5 << '\n';

    std::vector<Student*> students;
    students.push_back(&student1);
    students.push_back(&student2);
    students.push_back(&student3);
    students.push_back(&student5);
    students.push_back(&student6);
    students.push_back(&student7);
    std::cout << AverageScoreForGroup(students,1,4) << "\n";
    std::cout<<student6.GetId();




    return 0;
}
