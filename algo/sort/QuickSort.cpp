#include "QuickSort.h"

namespace NsQuickSort
{
	bool CQuickSort::QuickSort(std::vector<int> &num_vec)
	{
		return this->SubQuickSort(num_vec, 0, num_vec.size() - 1);
	}
	bool CQuickSort::SubQuickSort(std::vector<int> &num_vec
			, const int begin
			, const int end)
	{
		if (begin < end)
		{
			int part = this->Partition(num_vec, begin, end);
			this->SubQuickSort(num_vec, begin, part - 1);
			this->SubQuickSort(num_vec, part + 1, end);
		}
		return true;
	}
	int CQuickSort::Partition(std::vector<int> &num_vec
			, const std::vector<int>::size_type begin
			, const std::vector<int>::size_type end)
	{
		int target = num_vec.at(end);
		std::vector<int>::size_type i = begin - 1;
		for (std::vector<int>::size_type j = begin; j <= end - 1; ++ j)
		{
			if (num_vec.at(j) <= target)
			{
				++ i;
				this->Swap(num_vec[i], num_vec[j]);
			}
		}
		this->Swap(num_vec[i + 1], num_vec[end]);
		return i + 1;
	}
	bool CQuickSort::Swap(int &a, int &b)
	{
		int tmp = a;
		a = b;
		b = tmp;
		return true;
	}
}