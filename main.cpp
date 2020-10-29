#include <iostream>
#include "Fraction.h"
int main() {
    int a;
    Fraction b(15, 90);
    Fraction n (1, -2);
    Fraction c (2, 3);
    Fraction v (2, 3);
    b.MultiplyRational(n);
    b.Print();
    c.DivideRational(v);
    c.Print();
    


    return 0;
}
