
#include <gtest/gtest.h>
#include "Calculator.h"
#include <iostream>


TEST(IsCorrect, Simple) {
    Calculator a;
    EXPECT_EQ(a.IsCorrect("1+2"), true);
    EXPECT_EQ(a.IsCorrect("1/2"), true);
    EXPECT_EQ(a.IsCorrect("1--"), false);
    EXPECT_EQ(a.IsCorrect("1//2"), false);
    EXPECT_EQ(a.IsCorrect("-"), false);
    EXPECT_EQ(a.IsCorrect("1+2-"), false);
    EXPECT_EQ(a.IsCorrect("/1+2"), false);

}
TEST (IsCorrect, Float){
    Calculator a;
    EXPECT_EQ(a.IsCorrect("7.2348492+888.00939"),true);
    EXPECT_EQ(a.IsCorrect("0.02374/0.2349"),true);
    EXPECT_EQ(a.IsCorrect("-0.26+2.2"),true);
}
TEST (IsCorrect,Spaces){
    Calculator a;
    EXPECT_EQ(a.IsCorrect("   1 +    2"), true);
    EXPECT_EQ(a.IsCorrect(" 1 7 0  +   8 2"), true);
}
TEST (IsCorrect, BracketsCheck){
    Calculator a;
    EXPECT_EQ(a.IsCorrect("((1+2)"),false);
    EXPECT_EQ(a.IsCorrect(")1+2)"),false);
    EXPECT_EQ(a.IsCorrect("(1+2("),false);
    EXPECT_EQ(a.IsCorrect("+(1+2)"),false);
    EXPECT_EQ(a.IsCorrect("))1+2(("), false);
    EXPECT_EQ(a.IsCorrect("((1+2))"), true);
}
TEST (IsCorrect, ExprWithBrackets){
    Calculator a;
    EXPECT_EQ(a.IsCorrect("-(-1-2)"), true);
    EXPECT_EQ(a.IsCorrect("(1+2)+(1+2)"), true);
    EXPECT_EQ(a.IsCorrect("(1+2)+((-1)+(-1+2))"), true);
    EXPECT_EQ(a.IsCorrect("(((1+2)*6)/2)-1"),true);
    EXPECT_EQ(a.IsCorrect("2-(((1+2)*6)/2)"),true);
    EXPECT_EQ(a.IsCorrect("(1+2)*2)*)"), false);
}

TEST (IsCorrect, LongExpr) {
    Calculator a;
    EXPECT_EQ(a.IsCorrect("-1-2+3-6+1-7+8+1"), true);
    EXPECT_EQ(a.IsCorrect("1*2/3+6/7*5+7-222+1-1-5+7-8+9"), true);
    EXPECT_EQ(a.IsCorrect("111111111+222222222"), true);
    EXPECT_EQ(a.IsCorrect("(((3+4)/7+28*4)-1324)*2-(-2021)"), true);

}
TEST (IsCorrect, SuperTest){
    Calculator a;
    EXPECT_EQ(a.IsCorrect("(1.33+2)*((-0.1)+(-1.0+2))+((1.99+2)*7)-1"), true);
    EXPECT_EQ(a.IsCorrect("(12.56/123.6*896)-(-1/1235/89*52-65)/2563/(23+36*76-98)-89+(-9)"), true);
}

TEST(Calc, Simple) {
    Calculator a;
    EXPECT_EQ(a.GetResult("29+3"),32);
    EXPECT_EQ(a.GetResult("12-4"),8);
    EXPECT_EQ(a.GetResult("72/9"),8);
    EXPECT_EQ(a.GetResult("13*4"),52);
}
TEST (Calc, SimpleFloat){
    Calculator a;
    EXPECT_FLOAT_EQ(a.GetResult("6.24/2"),3.12);
    EXPECT_FLOAT_EQ(a.GetResult("1.001+0.205"),1.206);
    EXPECT_FLOAT_EQ(a.GetResult("1.000001+0.000001"),1.000002);
    EXPECT_FLOAT_EQ(a.GetResult("1.4*1.4"),1.96);
}
TEST(Calc, SimpleNegative){
    Calculator a;
    EXPECT_FLOAT_EQ(a.GetResult("12+(-3)"),9);
    EXPECT_FLOAT_EQ(a.GetResult("-8+27"),19);
    EXPECT_FLOAT_EQ(a.GetResult("-(12+3)"),-15);
    EXPECT_FLOAT_EQ(a.GetResult("-(-3-7)"),10);
    EXPECT_FLOAT_EQ(a.GetResult("(-2)*(-3)"),6);
}
TEST(Calc,Spaces){
    Calculator a;
    EXPECT_EQ(a.GetResult("1 000 000 + 2 000"),1002000);
    EXPECT_EQ(a.GetResult("1 2 3 + 1 "),124);
}
TEST(Calc, Final){
    Calculator a;
    EXPECT_EQ(a.GetResult("(1+2)-(1+2)"),0);
    EXPECT_EQ(a.GetResult("24/6/2"), 2);
    EXPECT_EQ(a.GetResult("-3-2*(-1)"),-1);
    EXPECT_EQ(a.GetResult("(2*4)+7/7 + (0.2/2 -1)/9"),8.9);
    EXPECT_EQ(a.GetResult("(1.2+0.6)*10-6+2*(-2-1)/(-1)"),18);
    EXPECT_EQ(a.GetResult("(((3+4)/7+28*4)-1324)*2-(-2021)"), -401);
    EXPECT_EQ(a.GetResult("( -84 / 6 ) * ( -1 ) - ( ( ( ( 23 - 32 / 4 ) / 3  + 6 * ( -1 ) ) - 17 ) / 12 - ( -3.5 ) )"), 12);
    EXPECT_FLOAT_EQ(a.GetResult("(12.56/123.6*896)-(-1/1235/89*52-65)/2563/(23+36*76-98)-89+(-9)"), -6.9501524);
}
TEST(Test, StringDoesNotChange){
    Calculator a;
    std::string temp="1+2+3+4";
    a.GetResult(temp);
    EXPECT_EQ(temp,"1+2+3+4");
    a.IsCorrect(temp);
    EXPECT_EQ(temp,"1+2+3+4");
}
