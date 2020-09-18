// TASK 9
#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
	double sum = 1, term, x, accuracy ;  //sum is assigned the value of the first term: 1
	double n0 = 1.0, n1 = 2.0; //explained later
	int k;
	std :: cout << "Enter x" << std :: endl;
	std :: cin >> x;
        std :: cout << "Enter the accuracy" << std :: endl;
	std :: cin >> k;
	accuracy = pow(10, -k-1);
	term = -(x)* n0 / n1; //the second term: -x*1/2
	if ((x > -1) && (x < 1) ) {   //checking the condition
		while (abs(term) >= accuracy) { // comparing term with accuracy
			sum += term;
			n0 += 2;
			n1 += 2;
            //terms differ in x*1/2, then x*3/4, x*5/6 and so on; so n0 and n1 - numerator and denominator of the difference between terms
		    term *= -(x) * n0 / n1;
		}
        std::cout << std::fixed;
        std::cout << std::setprecision(k);
        std::cout << "The result of calculating the Taylor series is " << sum << std::endl ;
        std::cout << "The result of a standard function is " << 1 / sqrt(1.0 + x) << std::endl;
	}
	else std :: cout << "Error";

	return 0;
}