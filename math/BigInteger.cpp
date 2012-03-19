#include "BigInteger.h"

namespace NsBigInteger
{
	CBigInteger::CBigInteger(const int num)
	{
		*this << num;
	}
	CBigInteger::CBigInteger(const std::string num)
	{
		*this << num;
	}
	CBigInteger &CBigInteger::operator<< (const int num)
	{
		this->m_sign = (num < 0);
		int tmp = num;
		this->m_digit.clear();
		while (tmp > 0)
		{
			this->m_digit.push_back(tmp % 10);
			tmp /= 10;
		}
		return *this;
	}
	CBigInteger &CBigInteger::operator<< (const std::string num)
	{
		if (num.at(0) == '-')
		{
			this->m_sign = true;
		}
		else
		{
			this->m_sign = false;
		}
		std::string tmp = num;
		if (tmp.at(0) == '-' || tmp.at(0) == '+')
		{
			tmp.erase(0);
		}
		this->m_digit.clear();
		for (int i = tmp.size() - 1; i >= 0; -- i)
		{
			if (tmp.at(i) >= '0' && tmp.at(i) <= '9')
			{
				this->m_digit.push_back(static_cast<int>(num.at(i) - '0'));
			}
			else if (tmp.at(i) == '.')
				continue;
			else
			{
				return *this;
			}
		}
		return *this;
	}
	bool operator== (const CBigInteger &n1, const CBigInteger &n2)
	{
		if (n1.m_sign != n2.m_sign || n1.m_digit.size() != n2.m_digit.size())
			return false;
		for (int i = 0; i < n1.m_digit.size(); ++ i)
		{
			if (n1.m_digit.at(i) != n2.m_digit.at(i))
			{
				return false;
			}
		}
		return true;
	}
	CBigInteger &CBigInteger::operator= (const CBigInteger &n)
	{
		this->m_sign = n.m_sign;
		this->m_digit = n.m_digit;
		return *this;
	}
	std::ostream &operator<< (std::ostream &os, const CBigInteger &c)
	{
		if (c.m_sign == true)
		{
			os << "-";
		}
		for (int i = c.m_digit.size() - 1; i >= 0; -- i)
		{
			os << c.m_digit.at(i);
		}
		return os;
	}
	CBigInteger operator+ (const CBigInteger &c1, const CBigInteger &c2)
	{
		CBigInteger tmp;
		if (c1.m_sign != c2.m_sign)
		{
			tmp = c2;
			tmp.m_sign = ! tmp.m_sign;
			return tmp/*c1 - tmp*/;	/// \todo
		}
		tmp.m_sign = c1.m_sign;
		int min_len = std::min(c1.m_digit.size(), c2.m_digit.size());
		int carry = 0;
		for (int i = 0; i < min_len; ++ i)
		{
			tmp.m_digit.push_back(c1.m_digit.at(i) + c2.m_digit.at(i) + carry);
			if (tmp.m_digit.at(i) >= 10)
			{
				carry = tmp.m_digit.at(i) / 10;
				tmp.m_digit[i] %= 10;
			}
		}
		for (int i = min_len; i < c1.m_digit.size(); ++ i)
		{
			tmp.m_digit.push_back(c1.m_digit.at(i));
		}
		for (int i = min_len; i < c2.m_digit.size(); ++ i)
		{
			tmp.m_digit.push_back(c2.m_digit.at(i));
		}
		if (carry > 0)
		{
			if (tmp.m_digit.size() > min_len)
			{
				tmp.m_digit[min_len] += carry;
			}
			else
			{
				tmp.m_digit.push_back(carry);
			}
		}
		return tmp;
	}
}