#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Fraction.h"
using namespace testing;


TEST(ConstructorTests, Parameter){
    Fraction a(1,2);
    EXPECT_EQ(a.GetNumerator(),1);
    EXPECT_EQ(a.GetDenominator(),2);

}
TEST (ConstructorTests, ParameterNegative1){
    Fraction a(-1,2);
    EXPECT_EQ(a.GetNumerator(),-1);
    EXPECT_EQ(a.GetDenominator(),2);
}
TEST(ConstructorTests, ParameterNegative2){
    Fraction a(-1,-2);
    EXPECT_EQ(a.GetNumerator(),1);
    EXPECT_EQ(a.GetDenominator(),2);
}
TEST(ConstructorTests, Copy){
    Fraction a(1,2);
    Fraction b(a);
    EXPECT_EQ(a.GetDenominator(),b.GetDenominator());
    EXPECT_EQ(a.GetNumerator(),b.GetNumerator());
}

TEST (ConstructorTests, CopyNegative){
    Fraction a(-7,12);
    Fraction b(a);
    EXPECT_EQ(a.GetNumerator(), b.GetNumerator());
    EXPECT_EQ(a.GetDenominator(),b.GetDenominator());
}
TEST(ConstructorTests, ZeroInDenominator) {
    EXPECT_THAT([]() {Fraction(1,0);},
            ThrowsMessage<std::invalid_argument>(HasSubstr("Error. Can't divide by zero")));
}
TEST(FunctionTests, Reduction) {
    Fraction a(2,4);
    EXPECT_EQ(a.GetNumerator(),1);
    EXPECT_EQ(a.GetDenominator(),2);
    Fraction b(0,3);
    EXPECT_FALSE(b.GetDenominator()==0);
}
TEST (FunctionTests, ReductionNeg){
    Fraction a(-2,6);
    EXPECT_EQ(a.GetNumerator(),-1);
    EXPECT_EQ(a.GetDenominator(),3);
}
TEST(FunctionTests, PrintDoesNotChangeTheValue){
    Fraction a(-1,2);
    a.Print();
    EXPECT_EQ(a.GetNumerator(),-1);
    EXPECT_EQ(a.GetDenominator(),2);
}

TEST(FunctionTests, Add) {
    Fraction a(1,3);
    Fraction b(1,3);
    a.AddRational(b);
    EXPECT_TRUE(a.GetNumerator()==2);
    EXPECT_TRUE(a.GetDenominator()==3);
    EXPECT_FALSE(b.GetNumerator()==2); //to make sure that "b" doesn't change after adding
}
TEST(FunctionTests, AddNegative){
    Fraction a(1,3);
    Fraction b(-2,3);
    a.AddRational(b);
    EXPECT_EQ(a.GetNumerator(), -1);
    EXPECT_EQ(a.GetDenominator(),3);
}
TEST (FunctionTests, Add1){
    Fraction a(1,2);
    Fraction b(1,-2);
    a.AddRational(b);
    EXPECT_EQ(a.GetNumerator(),0);
}

TEST(FunctionTests, Multiply){
    Fraction a(1,3);
    Fraction b(2,3);
    a.MultiplyRational(b);
    EXPECT_TRUE(a.GetNumerator()==2 && a.GetDenominator()==9);
    EXPECT_FALSE(b.GetDenominator()==9);
}
TEST(FunctionTests, MultiplyNegative){
    Fraction a(1,2);
    Fraction b(-1,2);
    a.MultiplyRational(b);  //positive*negative
    EXPECT_EQ(a.GetNumerator(),-1);
    EXPECT_EQ(a.GetDenominator(),4);
    EXPECT_NE(b.GetDenominator(),4);
    a.MultiplyRational(b);  //negative*negative
    EXPECT_TRUE(a.GetNumerator()==1 && a.GetDenominator()==8);
}

TEST(FunctionTests, Divide){
    Fraction a(1,3);
    Fraction b(2,3);
    a.DivideRational(b);
    EXPECT_TRUE(a.GetNumerator()==1 && a.GetDenominator()==2);
    EXPECT_NE(b.GetDenominator(),1);
}
TEST(FunctionTests, DivideNegative){
    Fraction a(-1,3);
    Fraction b(2,3);
    a.DivideRational(b);
    EXPECT_EQ(a.GetNumerator(), -1);
    EXPECT_EQ(a.GetDenominator(),2);
    EXPECT_TRUE(b.GetNumerator()==2 && b.GetDenominator()==3);
}
TEST(FunctionTests, DivideNegative1){
    Fraction a(-1,3);
    Fraction b(-2,3);
    a.DivideRational(b);
    EXPECT_EQ(a.GetNumerator(), 1);
    EXPECT_EQ(a.GetDenominator(),2);
}


