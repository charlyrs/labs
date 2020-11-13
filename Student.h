#pragma once
#include <string>

class Student {
private:
    std::string recordBook;
    static int quantity;
    std::string identifier;
    Student();

protected:
    char* name;
    int course;
    int group;
    int session;



public:
    ~Student();

    Student(char* name, int course, int group);
    Student(const Student&);

    std::string GetId ();
    std::string GetRecordBook();
    char* GetName ();
    int GetCourse();
    int GetGroup();
    void SetName(char* newname);
    void SetCourse(int newcourse);
    void SetGroup(int newgroup);
    int GetSession();
    virtual double AverageScore();
    friend std::ostream& operator<<(std::ostream &out, Student &student);



};

