#include <gtest/gtest.h>
#include "Student.h"
#include "StudentAfterSecondSession.h"
#include "StudentAfterFirstSession.h"
#include <string>


TEST(SConstructorTests, Parameter){
    Student a("Vova Bullatov", 1, 3);
    EXPECT_EQ(a.GetGroup(), 3);
    EXPECT_EQ(a.GetCourse(), 1);
    EXPECT_STREQ(a.GetName(), "Vova Bullatov");
//    EXPECT_EQ(a.GetId(), "V1");
//    EXPECT_EQ(a.GetRecordBook(),"10301");
    EXPECT_EQ(a.GetSession(),0);

}
TEST(SConstructorTests, Copy){
    Student a("Vova Bullatov", 1, 3);
    Student b(a);
    EXPECT_EQ(a.GetRecordBook(),b.GetRecordBook());
    EXPECT_NE(a.GetId(),b.GetId());
    EXPECT_EQ(b.GetGroup(), 3);
    EXPECT_EQ(b.GetCourse(), 1);
    EXPECT_STREQ(b.GetName(), "Vova Bullatov");
    EXPECT_NE(b.GetId(), a.GetId()); //ID changes
    EXPECT_EQ(a.GetRecordBook(), b.GetRecordBook());
}

TEST(SSetterTests, Name){
    Student a("Vova Bullatov", 1, 3);
    a.SetName("Vladimir Bullatov");
    EXPECT_STREQ(a.GetName(), "Vladimir Bullatov");
}
TEST(SSetterTests, Group){
    Student a("Vova Bullatov", 1, 3);
    a.SetGroup(4);
    EXPECT_EQ(a.GetGroup(),4);
}
TEST (SSetterTests, Course){
    Student a("Vova Bullatov", 1, 3);
    a.SetCourse(2);
    EXPECT_EQ(a.GetCourse(),2);
}
TEST (SFunctions, AverageScore){
    Student a("Vova Bullatov", 1, 3);

    EXPECT_EQ(a.AverageScore(),0);
}
TEST (SOperator, Output){
    Student a("Vova Bullatov", 1, 3);
    std::stringstream ss;
    std::string res;
    std::string temp;
    ss << a;
    while (ss >> temp){
        res= res + temp + "  " ;
    }

    EXPECT_EQ(res, "Name:  Vova  Bullatov  Course:  1  Group:  3  ");
}

/////////////

TEST (S1ConstructorTests, Parameter){
    int marks[4]={10,9,8,10};
    StudentAfterFirstSession s("A", 1, 1, marks);
    EXPECT_STREQ(s.GetName(), "A");
    EXPECT_EQ(s.GetSession(),1);
    EXPECT_EQ(s.GetCourse(),1);
    EXPECT_EQ(s.GetGroup(),1);

    EXPECT_EQ(s.GetFirstSessionMarks()[0],10);
    EXPECT_EQ(s.GetFirstSessionMarks()[1],9);
    EXPECT_EQ(s.GetFirstSessionMarks()[2],8);
    EXPECT_EQ(s.GetFirstSessionMarks()[3],10);
}
TEST (S1ConstructorTests, ParameterWithStudent){
    Student a("Georgiy Razmyslovich", 1, 3);
    int marks[4]={9,7,8,10};
    StudentAfterFirstSession b(a,marks);
    EXPECT_STREQ(b.GetName(), "Georgiy Razmyslovich");
    EXPECT_EQ(b.GetSession(),1);
    EXPECT_EQ(b.GetCourse(),1);
    EXPECT_EQ(b.GetGroup(),3);
    EXPECT_EQ(a.GetRecordBook(),b.GetRecordBook());
    EXPECT_NE(a.GetId(),b.GetId());
//    EXPECT_EQ(b.GetRecordBook(),"10301");
//    EXPECT_EQ(a.GetRecordBook(),"10301"); //checking that RB doesn't change
//    EXPECT_NE(a.GetId(),b.GetId()); //unique ID
//    EXPECT_EQ(b.GetId(),"G2");
    EXPECT_EQ(b.GetFirstSessionMarks()[0],9);
    EXPECT_EQ(b.GetFirstSessionMarks()[1],7);
    EXPECT_EQ(b.GetFirstSessionMarks()[2],8);
    EXPECT_EQ(b.GetFirstSessionMarks()[3],10);

}
TEST (S1ConstructorTests, Copy){
    int marks[4]={5,9,8,10};
    StudentAfterFirstSession a("Georgiy Razmyslovich", 1, 3, marks);
    StudentAfterFirstSession b(a);
    EXPECT_STREQ(b.GetName(), "Georgiy Razmyslovich");
    EXPECT_EQ(b.GetSession(),1);
    EXPECT_EQ(b.GetCourse(),1);
    EXPECT_EQ(b.GetGroup(),3);
    EXPECT_EQ(a.GetRecordBook(),b.GetRecordBook());
    EXPECT_NE(a.GetId(),b.GetId());
//    EXPECT_EQ(b.GetRecordBook(),"10301");
//    EXPECT_EQ(a.GetRecordBook(),"10301"); //checking that RB doesn't change
//    EXPECT_NE(a.GetId(),b.GetId());
//    EXPECT_EQ(b.GetId(),"G2");
    EXPECT_EQ(b.GetFirstSessionMarks()[0],5);
    EXPECT_EQ(b.GetFirstSessionMarks()[1],9);
    EXPECT_EQ(b.GetFirstSessionMarks()[2],8);
    EXPECT_EQ(b.GetFirstSessionMarks()[3],10);

}
TEST (S1Operstor, Output){
    int m[4]={10,10,10,10};
    StudentAfterFirstSession a("Vova Bullatov", 1, 3, m);
    std::stringstream ss;
    std::string res;
    std::string temp;
    ss << a;
    while (ss >> temp){
        res= res + temp + "  " ;
    }
    EXPECT_EQ(res, "Name:  Vova  Bullatov  Course:  1  Group:  3  Marks  after  first  session  are  10  10  10  10  ");

}
TEST (S1FunctionTests, SetMarks){
    int marks[4]={10,9,8,10};
    StudentAfterFirstSession a("Georgiy Razmyslovich", 1, 3, marks);
    int newmarks[4]={8,10,10,9};
    a.SetFirstSessionMarks(newmarks);
    EXPECT_EQ(a.GetFirstSessionMarks()[0],8);
    EXPECT_EQ(a.GetFirstSessionMarks()[1],10);
    EXPECT_EQ(a.GetFirstSessionMarks()[2],10);
    EXPECT_EQ(a.GetFirstSessionMarks()[3],9);
}
TEST (S1FunctionTests, AverageScore){
    int marks[4]={10,9,8,10};
    StudentAfterFirstSession a("Georgiy Razmyslovich", 1, 3, marks);
    double average=(10+9+8+10)/4.0;
    EXPECT_EQ(a.AverageScore(), average);
}

//////////////////
TEST (S2ConstructorTest, Parameter){
    int marks1[4]={10,9,8,7};
    int marks2[5]={6,7,8,9,10};
    StudentAfterSecondSession a("B",2,11,marks1,marks2);
    EXPECT_STREQ(a.GetName(), "B");
    EXPECT_EQ(a.GetGroup(),11);
    EXPECT_EQ(a.GetCourse(),2);
    EXPECT_EQ(a.GetSession(),2);
    EXPECT_EQ(a.GetFirstSessionMarks()[0],10);
    EXPECT_EQ(a.GetFirstSessionMarks()[1],9);
    EXPECT_EQ(a.GetFirstSessionMarks()[2],8);
    EXPECT_EQ(a.GetFirstSessionMarks()[3],7);
    EXPECT_EQ(a.GetSecondSessionMarks()[0],6);
    EXPECT_EQ(a.GetSecondSessionMarks()[1],7);
    EXPECT_EQ(a.GetSecondSessionMarks()[2],8);
    EXPECT_EQ(a.GetSecondSessionMarks()[3],9);
    EXPECT_EQ(a.GetSecondSessionMarks()[4],10);
}
TEST (S2ConstructorTest, ParameterWithS1){
    int marks[4]={10,9,8,10};
    StudentAfterFirstSession a("Georgiy Razmyslovich", 1, 3, marks);
    int marks2[5]={10,7,4,10,8};
    StudentAfterSecondSession b(a,marks2);
    EXPECT_STREQ(a.GetName(), b.GetName());
    EXPECT_EQ(a.GetGroup(),b.GetGroup());
    EXPECT_EQ(a.GetCourse(),b.GetCourse());
    EXPECT_EQ(b.GetSession(),2);
    EXPECT_EQ(b.GetFirstSessionMarks()[0],10);
    EXPECT_EQ(b.GetFirstSessionMarks()[1],9);
    EXPECT_EQ(b.GetFirstSessionMarks()[2],8);
    EXPECT_EQ(b.GetFirstSessionMarks()[3],10);
    EXPECT_EQ(b.GetSecondSessionMarks()[0],10);
    EXPECT_EQ(b.GetSecondSessionMarks()[1],7);
    EXPECT_EQ(b.GetSecondSessionMarks()[2],4);
    EXPECT_EQ(b.GetSecondSessionMarks()[3],10);
    EXPECT_EQ(b.GetSecondSessionMarks()[4],8);

    EXPECT_EQ(a.GetRecordBook(),b.GetRecordBook());
    EXPECT_NE(a.GetId(),b.GetId());
}
TEST(S2ConstructorTests, Copy){
    int marks[4]={10,9,8,10};
    int marks2[5]={10,7,4,10,8};
    StudentAfterSecondSession a("Georgiy Razmyslovich", 1, 3, marks,marks2);
    StudentAfterSecondSession b (a);
    EXPECT_STREQ(a.GetName(), b.GetName());
    EXPECT_EQ(a.GetGroup(),b.GetGroup());
    EXPECT_EQ(a.GetCourse(),b.GetCourse());
    EXPECT_EQ(b.GetSession(),2);
    EXPECT_EQ(b.GetFirstSessionMarks()[0],10);
    EXPECT_EQ(b.GetFirstSessionMarks()[1],9);
    EXPECT_EQ(b.GetFirstSessionMarks()[2],8);
    EXPECT_EQ(b.GetFirstSessionMarks()[3],10);
    EXPECT_EQ(b.GetSecondSessionMarks()[0],10);
    EXPECT_EQ(b.GetSecondSessionMarks()[1],7);
    EXPECT_EQ(b.GetSecondSessionMarks()[2],4);
    EXPECT_EQ(b.GetSecondSessionMarks()[3],10);
    EXPECT_EQ(b.GetSecondSessionMarks()[4],8);

    EXPECT_EQ(a.GetRecordBook(),b.GetRecordBook());
    EXPECT_NE(a.GetId(),b.GetId());
}
TEST (S2Functions, SetMarks){
    int marks1[4]={10,9,8,7};
    int marks2[5]={6,7,8,9,10};
    StudentAfterSecondSession a("B",2,11,marks1,marks2);
    int newmarks[5]={8,8,9,10};
    a.SetSecondSessionMarks(newmarks);
    EXPECT_EQ(a.GetSecondSessionMarks()[0],8);
    EXPECT_EQ(a.GetSecondSessionMarks()[0],8);
    EXPECT_EQ(a.GetSecondSessionMarks()[1],8);
    EXPECT_EQ(a.GetSecondSessionMarks()[2],9);
    EXPECT_EQ(a.GetSecondSessionMarks()[3],10);
}
TEST (S2Operator, Output){
    int marks[4]={10,9,8,10};
    int marks2[5]={10,7,4,10,8};
    StudentAfterSecondSession a("Georgiy Razmyslovich", 1, 3, marks,marks2);
    std::stringstream ss;
    std::string res;
    std::string temp;
    ss << a;
    while (ss >> temp){
        res= res + temp + "  " ;
    }
    EXPECT_EQ(res, "Name:  Georgiy  Razmyslovich  Course:  1  Group:  3  Marks  after  the  first  session  are  10  9  8  10 "
                   " Marks  after  the  second  session  are  10  7  4  10  8  ");
}
TEST (S2Functions, Average){
    int marks[4]={10,9,8,10};
    int marks2[5]={10,7,4,10,8};
    StudentAfterSecondSession a("Georgiy Razmyslovich", 1, 3, marks,marks2);
    double res=(10+9+8+10+10+7+4+10+8)/9.0;
    EXPECT_EQ(res,a.AverageScore());
}
TEST (Qualities, Student){
    Student a("A",1,1);
    Student b("B",1,2);
    EXPECT_NE(a.GetId(),b.GetId());
    EXPECT_NE(a.GetRecordBook(),b.GetRecordBook());
    Student c(a);
    EXPECT_EQ(a.GetRecordBook(),c.GetRecordBook());
    EXPECT_NE(a.GetId(),c.GetId());
}
TEST(Qualities, S1){
    int marks[4]={6,6,6,6};
    StudentAfterFirstSession a("A",1,1, marks);
    StudentAfterFirstSession b("B",1,2, marks);
    EXPECT_NE(a.GetId(),b.GetId());
    EXPECT_NE(a.GetRecordBook(),b.GetRecordBook());
    StudentAfterFirstSession c(a);
    EXPECT_EQ(a.GetRecordBook(),c.GetRecordBook());
    EXPECT_NE(a.GetId(),c.GetId());
}
TEST (Qualities, S2){
    int marks[4]={6,6,6,6};
    int marks1[5]={7,7,7,7,7};
    StudentAfterSecondSession a("A",1,1, marks, marks1);
    StudentAfterSecondSession b("B",1,2, marks, marks1);
    EXPECT_NE(a.GetId(),b.GetId());
    EXPECT_NE(a.GetRecordBook(),b.GetRecordBook());
    StudentAfterSecondSession c(a);
    EXPECT_EQ(a.GetRecordBook(),c.GetRecordBook());
    EXPECT_NE(a.GetId(),c.GetId());
}
TEST (SettersForChildren, Name){
    int marks[4]={9,6,8,6};
    StudentAfterFirstSession a("A",1,1, marks);
    a.SetName("B");
    EXPECT_STREQ(a.GetName(),"B");
    int marks1[5]={9,8,10,7,7};
    StudentAfterSecondSession b(a,marks1);
    b.SetName("C");
    EXPECT_STREQ(b.GetName(),"C");
}
TEST (SettersForChildren, Group){
    int marks[4]={9,6,8,6};
    StudentAfterFirstSession a("A",1,1, marks);
    a.SetGroup(2);
    EXPECT_EQ(a.GetGroup(),2);
    int marks1[5]={9,8,10,7,7};
    StudentAfterSecondSession b(a,marks1);
    b.SetGroup(3);
    EXPECT_EQ(b.GetGroup(),3);
}
TEST (SettersForChildren, Course){
    int marks[4]={9,6,8,6};
    StudentAfterFirstSession a("A",1,1, marks);
    a.SetCourse(2);
    EXPECT_EQ(a.GetCourse(),2);
    int marks1[5]={9,8,10,7,7};
    StudentAfterSecondSession b(a,marks1);
    b.SetCourse(3);
    EXPECT_EQ(b.GetCourse(),3);
}


