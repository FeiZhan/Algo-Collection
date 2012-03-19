#ifndef _COMPLEX_
#define _COMPLEX_

#include <iostream>

namespace NsComplex
{
	class CComplex
	{
	public:
		CComplex(void);
		CComplex(const double real, const double imag);
		~CComplex(void);
		double Mod(void);
		double Angle(void);
		CComplex Conjugate(void);
		friend bool operator== (const CComplex &c1, const CComplex &c2);
		CComplex &operator= (const CComplex &c);
		friend std::ostream &operator<< (std::ostream &os, const CComplex &c);
		friend CComplex operator+ (const CComplex &c1, const CComplex &c2);
		friend CComplex operator+ (const double d, const CComplex &c);
		friend CComplex operator+ (const CComplex &c, const double d);
	protected:
	private:
		double real, imag;
	};
}

#endif