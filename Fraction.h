
#ifndef LAB6V7_FRACTION_H
#define LAB6V7_FRACTION_H


class Fraction {
    int numerator;
    int denominator;
    int Nod ();
    Fraction();
    Fraction Reduction ();

public:
        Fraction(int a=1, int b=1);
        int GetNumerator ();
        int GetDenominator ();
        void AddRational (const Fraction&);
        void MultiplyRational(const Fraction&);
        void DivideRational(const Fraction&);
        void Print ();



};


#endif //LAB6V7_FRACTION_H
