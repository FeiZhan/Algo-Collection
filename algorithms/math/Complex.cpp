#include <cmath>
#include "Complex.h"

namespace NsComplex
{
	CComplex::CComplex(void)
	{
		this->real = this->imag = NULL;
	}
	CComplex::CComplex(const double real, const double imag)
	{
		this->real = real;
		this->imag = imag;
	}
	CComplex::~CComplex(void)
	{}
	double CComplex::Mod(void)
	{
		return sqrt(this->real * this->real + this->imag * this->imag);
	}
	double CComplex::Angle(void)
	{
		return atan(this->imag / this->real);
	}
	CComplex CComplex::Conjugate(void)
	{
		return CComplex(this->real, - this->imag);
	}
	bool operator== (const CComplex &c1, const CComplex &c2)
	{
		return (c1.real == c2.real && c1.imag == c2.imag);
	}
	CComplex &CComplex::operator= (const CComplex &c)
	{
		this->real = c.real;
		this->imag = c.imag;
		return *this;
	}
	std::ostream &operator<< (std::ostream &os, const CComplex &c)
	{
		return os << "Complex(" << c.real << ", " << c.imag << ")";
	}
	CComplex operator+ (const CComplex &c1, const CComplex &c2)
	{
		return CComplex(c1.real + c2.real, c1.imag + c2.imag);
	}
	CComplex operator+ (const double d, const CComplex &c)
	{
		return CComplex(c.real + d, c.imag);
	}
	CComplex operator+ (const CComplex &c, const double d)
	{
		return CComplex(c.real + d, c.imag);
	}
}