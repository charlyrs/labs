#include "Stack.h"
#include <gtest/gtest.h>

TEST(Constr,Simple){
    Stack<int> a;
    EXPECT_EQ(a.Size(),0);
    EXPECT_EQ(a.isEmpty(),true);
    EXPECT_EQ(a.isEmpty(),true);
    EXPECT_ANY_THROW(a.peak());
    EXPECT_ANY_THROW(a.pop());
}
TEST(Func, Push){
    Stack<int> a;
    a.push(2);
    EXPECT_EQ(a.peak(),2);
    a.push(100);
    EXPECT_EQ(a.peak(),100);
}
TEST(Func, Pop){
    Stack<double> a;
    a.push(14.7);
    a.push(0.2);
    a.push(10);
    EXPECT_EQ(a.pop(),10);
    EXPECT_EQ(a.Size(),2);
    EXPECT_EQ(a.pop(),0.2);
    EXPECT_EQ(a.Size(),1);
    EXPECT_EQ(a.pop(),14.7);
    EXPECT_EQ(a.isEmpty(),true);
    EXPECT_ANY_THROW(a.pop());
}
TEST(Oper, Push){
    Stack<char> a;
    a << 'a';
    a << 'b';
    a << 'c';
    EXPECT_EQ(a.peak(),'c');
    EXPECT_EQ(a.Size(),3);
}
TEST(Oper, Pop){
    Stack<int> a;
    a << 2;
    int check;
    a >> check;
    EXPECT_EQ(check,2);
    EXPECT_EQ(a.Size(),0);
}
TEST(Oper, Prisvaivanie){
    Stack<int> a;
    a.push(12);
    a.push(0);
    a.push(5);
    a.push(27);
    Stack<int> b;
    b=a;
    EXPECT_EQ(b.pop(),a.pop());
    EXPECT_EQ(b.pop(),a.pop());
    EXPECT_EQ(b.pop(),a.pop());
    EXPECT_EQ(b.pop(),a.pop());
}
TEST(Comparison, Eq){
    Stack<int> a;
    Stack<int> b;
    a.push(1);
    a.push(2);
    a.push(3);
    b.push(1);
    b.push(2);
    b.push(3);
    EXPECT_EQ(a==b,true);
    EXPECT_EQ(a!=b, false);
}
TEST(Comparison, All){
    Stack<int> a;
    Stack<int> b;
    a.push(9);
    a.push(7);
    a.push(75);
    b.push(1);
    b.push(2);
    EXPECT_EQ(a!=b, true);
    EXPECT_EQ(a>b, true);
    EXPECT_EQ(a<b, false);
}
TEST(ExtendCapacity, Simple){
    Stack<int> a;
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    a.push(0);
    EXPECT_NO_THROW(a.push(1));
}
TEST(Oper, Brackets){
    Stack<int> a;
    a.push(89);
    a.push(-7);
    a.push(32);
    a.push(4);
    EXPECT_EQ(a[0],89);
    EXPECT_EQ(a[1],-7);
    EXPECT_EQ(a[2],32);
    EXPECT_EQ(a[3],4);
}

