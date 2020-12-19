#pragma once

#include <string>
#include <regex>
#include <sstream>
#include <iostream>
#include "Stack.h"

class Calculator {
private:
    std::string RemoveSpaces(std::string str) {
        str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
        return str;
    }

    bool CheckBrackets(std::string str) {
        std::regex a("[(]");
        std::regex b("[)]");
        std::smatch res;
        std::string str1 = str;
        int left = 0;
        int right = 0;
        while (regex_search(str, res, a)) {
            left++;
            str = res.suffix();
        }
        while (regex_search(str1, res, b)) {
            right++;
            str1 = res.suffix();
        }
        return left == right;
    }
    std::string FindNumber(std::string &str) {
        std::regex doubleExpression("(\\-)?[0-9]+(\\.[0-9]+)?");
        std::smatch res;
        regex_search(str, res, doubleExpression);
        std::string num = res[0];
        str = res.suffix();
        return num;
    }

    char FindOperators(std::string &str) {
        std::regex oper("[\\+\\-\\*\\^\\/]");
        std::smatch res;
        std::regex_search(str, res, oper);
        std::string opers = res[0];
        str = res.suffix();
        return opers[0];
    }

    int priority(char oper) {
        int res = -1;
        if (oper == '+' || oper == '-') res = 1;
        if (oper == '*' || oper == '/') res = 2;
        return res;
    }

    std::string ConvertToPolish(std::string &str) {
        str = RemoveSpaces(str);
        if (str[0] == '-') {
            str.insert(1, "1*");    // -(3+2) -> -1*(3+2)
        }
        std::string polish;
        Stack<char> st;
        bool PrevIsDigit=false;
        bool PrevIsClosedBracket=false;
        if (IsCorrect(str)) {
            while (str.length() != 0) {
                char x = str[0];
                if (isdigit(x)) {
                    polish += FindNumber(str);
                    polish += " ";
                    PrevIsDigit=true;
                    PrevIsClosedBracket=false;
                    continue;
                }
                if (x == '(') {
                    st.push(x);
                    str.erase(0, 1);
                    PrevIsDigit=false;
                    PrevIsClosedBracket=false;
                    continue;
                }
                if (x == ')') {
                    while (st.peak() != '(') {
                        char temp = st.pop();
                        polish += temp;
                        polish += " ";
                    }
                    st.pop();
                    str.erase(0, 1);
                    PrevIsDigit=false;
                    PrevIsClosedBracket=true;
                    continue;
                }
                if (priority(x) > 0) {
                    if (x == '-') {                            // to find negative numbers in expressions like :
                        if (st.isEmpty() && polish.empty()) {  // -1+2
                            polish += FindNumber(str);
                            polish += " ";
                            PrevIsDigit=true;
                            PrevIsClosedBracket=false;
                            continue;
                        }
                        if (!st.isEmpty() && !PrevIsDigit && !PrevIsClosedBracket) { // 2+(-1)
                            polish += FindNumber(str);
                            polish += " ";
                            PrevIsDigit=true;
                            PrevIsClosedBracket=false;
                            continue;
                        }
                    }
                    while (!st.isEmpty() && priority(st.peak()) >= priority(x)) {
                        char temp = st.pop();
                        polish += temp;
                        polish += " ";
                    }
                    st.push(FindOperators(str));
                    PrevIsDigit=false;
                    PrevIsClosedBracket=false;
                    continue;
                }
            }
            while (!st.isEmpty()) {
                polish += st.pop();
                polish += " ";
            }
            return polish;
        } else {
            std::cout << "Wrong expression!!!!";
            std::exit(1);
        }
    }

    double Calculate(double a, double b, char oper) {
        double result;
        if (priority(oper) == 1) {
            if (oper == '+') result = a + b;
            if (oper == '-') result = b - a;
        }
        if (priority(oper) == 2) {
            if (oper == '*') result = a * b;
            if (oper == '/') result = b / a;
        }
        return result;
    }

public:

    bool IsCorrect(std::string str) {
        str = RemoveSpaces(str);
        if (priority(str[0])>0 && str[0]!='-') return false;
       // std::regex zero("(\\/0)");
        std::smatch temp;
       // if (regex_search(str,temp,zero)) return false;
        if (!CheckBrackets(str)) return false;
        bool result;
        // :)
       std::regex exp(
                "((\\-)?(((\\()?)*((\\-)?[0-9]+(\\.[0-9]+)?)((\\))?)*)*(\\-|\\+|\\*|\\/)*(((\\()?)*((\\-)?[0-9]+(\\.[0-9]+)?)((\\))?)*))*");
        result = std::regex_match(str, exp);
        return result;
    }



    double GetResult(std::string str) {
        str = ConvertToPolish(str);
        std::regex doubleExpression("(\\-)?[0-9]+(\\.[0-9]+)?");
        Stack<double> result;
        std::stringstream ss;
        ss << str;
        std::string item;
        while (ss >> item) {
            if (std::regex_match(item, doubleExpression)) {
                double a = std::atof(item.c_str());
                result.push(a);
                continue;
            }
            if (priority(item[0]) > 0) {
                double a = result.pop();
                double b = result.pop();
                double temp = Calculate(a, b, item[0]);
                result.push(temp);
            }
        }
        if (result.Size() == 1) return result.pop();
        else throw "aaa";
    }
};
