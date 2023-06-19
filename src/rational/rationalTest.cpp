#include <iostream>
#include "rational.hpp"


int main()
{
    ilrd::Rational r1;
    ilrd::Rational r2(4);
    ilrd::Rational r3(1,2);

    std::cout << "R1: ";
    std::cout << r1.Numerator() << "/" 
                << r1.Denominator() << std::endl;

    std::cout << "R2: ";
    std::cout << r2.Numerator() << "/" 
                << r2.Denominator() << std::endl;

    std::cout << "R3: ";
    std::cout << r3.Numerator() << "/" 
                << r3.Denominator() << std::endl;

    r1 = r3;
    std::cout << "R1 = R3: ";
    std::cout << r1.Numerator() << "/" 
                << r1.Denominator() << std::endl;

    r1 += r2;
    std::cout << "R1 += R2: ";
    std::cout << r1.Numerator() << "/" 
                << r1.Denominator() << std::endl;

    r2 = r1 + r3;
    std::cout << "R2 = R1 + R3: ";
    std::cout << r2.Numerator() << "/" 
                << r2.Denominator() << std::endl;

    ilrd::Rational r4 = r2 - r1;
    std::cout << "R4 = R2 - R1: ";
    std::cout << r4.Numerator() << "/" 
                << r4.Denominator() << std::endl;

    ilrd::Rational r5 = r4 - r2;
    std::cout << "R5 = R4 - R2: ";
    std::cout << r5.Numerator() << "/" 
                << r5.Denominator() << std::endl;

    ilrd::Rational r6(-1, 2);

    r6 *= r5;
    std::cout << "R6 *= R5: ";
    std::cout << r6.Numerator() << "/" 
                << r6.Denominator() << std::endl;
    

    return 0;
}