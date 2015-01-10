#include "MaxSeqSum.h"

namespace NsMaxSeqSum
{
	CMaxSeqSum &CMaxSeqSum::operator<< (const std::vector<int> &seq)
	{
		this->m_seq = seq;
		return *this;
	}
	int CMaxSeqSum::MaxSeqSumSimple(void)
	{
		int this_sum, max_sum = 0;
		for (std::vector<int>::size_type i = 0; i < this->m_seq.size(); ++ i)
		{
			this_sum = 0;
			for (std::vector<int>::size_type j = i; j < this->m_seq.size(); ++ j)
			{
				this_sum += this->m_seq.at(j);
				if (this_sum > max_sum)
				{
					max_sum = this_sum;
				}
			}
		}
		return max_sum;
	}
	int CMaxSeqSum::MaxSeqSumRec(void)
	{
		return this->MaxSeqSumRec1(0, this->m_seq.size() - 1);
	}
	int CMaxSeqSum::MaxSeqSumRec1(const int left, const int right)
	{
		if (left > right)
		{
			return 0;
		}
		else if (left == right)
		{
			if (this->m_seq.at(left) > 0)
				return this->m_seq.at(left);
			else
				return 0;
		}
		int center = (left + right) / 2;
		int max_left = this->MaxSeqSumRec1(left, center);
		int max_right = this->MaxSeqSumRec1(center + 1, right);
		int left_sum = 0, max_left_sum = 0;
		for (int i = center; i >= left; -- i)
		{
			left_sum += this->m_seq.at(i);
			if (left_sum > max_left_sum)
				max_left_sum = left_sum;
		}
		int right_sum = 0, max_right_sum = 0;
		for (int i = center + 1; i <= right; ++ i)
		{
			right_sum += this->m_seq.at(i);
			if (right_sum > max_right_sum)
				max_right_sum = right_sum;
		}
		return std::max(max_left_sum + max_right_sum
			, std::max(max_left, max_right));
	}
	std::ostream &operator<< (std::ostream &os, const CMaxSeqSum &seq)
	{
		os << "MaxSeqSum";
		for (std::vector<int>::size_type i = 0; i < seq.m_seq.size(); ++ i)
		{
			os << " " << seq.m_seq.at(i);
		}
		return os;
	}
}