#include <iostream>
#include "Fraction.h"
int main() {
    Fraction b(15, 90);
    Fraction n(2, -1);
    Fraction c(2, 3);
    Fraction v(2, 3);
    b.MultiplyRational(n);
    b.Print();
    c.AddRational(v);
    c.Print();
    std::cout << c.GetNumerator();
    


    return 0;
}
