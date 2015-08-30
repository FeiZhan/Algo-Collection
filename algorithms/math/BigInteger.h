#ifndef _BIG_INTEGER_
#define _BIG_INTEGER_

#include <iostream>
#include <vector>
#include <string>

namespace NsBigInteger
{
	class CBigInteger
	{
	public:
		CBigInteger(const int num = 0);
		CBigInteger(const std::string num);
		CBigInteger &operator<< (const int num);
		CBigInteger &operator<< (const std::string num);
		friend bool operator== (const CBigInteger &n1, const CBigInteger &n2);
		CBigInteger &operator= (const CBigInteger &n);
		friend std::ostream &operator<< (std::ostream &os, const CBigInteger &c);
		friend CBigInteger operator+ (const CBigInteger &c1
			, const CBigInteger &c2);
	protected:
	private:
		bool m_sign;
		std::vector<int> m_digit;
	};
}

#endif