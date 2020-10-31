
#include "Fraction.h"
#include <iostream>
Fraction::Fraction(int a, int b) {
    numerator=a;
    if (b!=0) denominator=b;
    else {std::cout << "Error. Can't divide by zero\n";
    std::exit(1);}
     Reduction();
}
Fraction::Fraction(const Fraction &a) {
    numerator=a.numerator;
    denominator=a.denominator;
}
int Fraction::GetNumerator() {
    return numerator;
}
int Fraction::GetDenominator() {
    return denominator;
}
void Fraction::AddRational(const Fraction& a) {
    numerator=numerator*a.denominator+denominator*a.numerator;
    denominator = denominator*a.denominator;
    Reduction();

}
void Fraction::MultiplyRational(const Fraction &a){

    numerator=a.numerator*numerator;
    denominator=a.denominator*denominator;
    Reduction();


};
void Fraction::DivideRational(const Fraction& a) {
    numerator*=a.denominator;
    denominator*=a.numerator;

}
void Fraction::Print() {
    Reduction();
    int i=0;
    if (std::abs (numerator)>std::abs(denominator)){
        i=numerator/denominator;
        std::cout << i << ".";
        i=std::abs(i*denominator);
        std::cout << (std::abs(numerator) - i) << "/" << std::abs(denominator) << " ";
    }
    if (std::abs(numerator)<std::abs(denominator)) {
        if (numerator * denominator > 0) {
            std::cout << (std::abs(numerator) - i) << "/" << std::abs(denominator) << " ";
        } else if (numerator == 0) std::cout << 0;
        else std::cout << "-" << (std::abs(numerator) - i) << "/" << std::abs(denominator) << " ";
    }
    if (std::abs(numerator)==std::abs(denominator)) std::cout << 1;

}
int Fraction::Nod (){
    int a=std::abs(numerator);
    int b=std::abs(denominator);
    int nod=1;
    if (a>b) std::swap (a,b);
    for (int i=2; i<=a; ++i){
        if (a%i == 0 && b%i==0){
            nod = i;
        }
    }
    return nod;

}
void Fraction::Reduction() {
    int nod = Nod();
    numerator /= nod;
    denominator /= nod;

}



