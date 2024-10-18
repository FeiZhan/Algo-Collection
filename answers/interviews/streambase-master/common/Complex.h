#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex();
    Complex(double r, double i);
    Complex(string input);
    string toString();
    double getReal();
    double getImaginary();
    double abs();
};
