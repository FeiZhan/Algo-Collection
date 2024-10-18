#include <iostream>
#include <cmath>

#include <Helper.h>
#include <Complex.h>

using namespace std;

Complex::Complex()
{
    this->real = 0.0;
    this->imaginary = 0.0;
}

Complex::Complex(double r, double i)
{
    this->real = r;
    this->imaginary = i;
}

Complex::Complex(string input)
{
    vector<string> tokens = Helper::split(input, ',');
    this->real = stod(tokens[0]);
    this->imaginary = stod(tokens[1]);
}

string Complex::toString()
{
    return to_string(this->real) + "," + to_string(this->imaginary);
}

double Complex::getReal()
{
    return this->real;
}

double Complex::getImaginary()
{
    return this->imaginary;
}

double Complex::abs()
{
    return hypot(this->real, this->imaginary);
}
