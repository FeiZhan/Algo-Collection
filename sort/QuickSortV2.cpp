#include "QuickSortV2.h"

namespace NsQuickSortV2
{
	CQuickSortV2 &CQuickSortV2::operator<< (const int num)
	{
		this->num_vec.push_back(num);
		return *this;
	}
	bool CQuickSortV2::QuickSort(void)
	{
		return this->SubQuickSort(0, this->num_vec.size() - 1);
	}
	bool CQuickSortV2::SubQuickSort(const int left, const int right)
	{
		if (right - left <= 0)
			return true;
		else if (right - left == 1)
		{
			int tmp = this->num_vec.at(left);
			if (this->num_vec.at(left) > this->num_vec.at(right))
			{
				this->Swap(left, right);
			}
			return true;
		}
		int pivot = this->Median3(left, right);
		int i = left;
		 /// \note (right - 1) has already defined in Median3, so skip it.
		int j = right - 1;
		while (true)
		{
			while (this->num_vec.at(++ i) < pivot)
				NULL;
			while (this->num_vec.at(-- j) > pivot)
				NULL;
			if (i < j)
			{
				this->Swap(i, j);
			}
			else
				break;
		}
		this->Swap(i, right - 1);
		this->SubQuickSort(left, i - 1);
		this->SubQuickSort(i + 1, right);
		return true;
	}
	bool CQuickSortV2::Swap(const int pos1, const int pos2)
	{
		int tmp = this->num_vec.at(pos1);
		this->num_vec[pos1] = this->num_vec[pos2];
		this->num_vec[pos2] = tmp;
		return true;
	}
	int CQuickSortV2::Median3(const int left, const int right)
	{
		int center = (left + right) / 2;
		if (this->num_vec.at(left) > this->num_vec.at(center))
		{
			this->Swap(left, center);
		}
		if (this->num_vec.at(left) > this->num_vec.at(right))
		{
			this->Swap(left, right);
		}
		if (this->num_vec.at(center) > this->num_vec.at(right))
		{
			this->Swap(center, right);
		}
		this->Swap(center, right - 1);
		return this->num_vec.at(right - 1);
	}
	std::ostream &operator<< (std::ostream &os, CQuickSortV2 &sort)
	{
		os << "QuickSortV2";
		for (size_t i = 0; i < sort.num_vec.size(); ++ i)
		{
			os << " " << sort.num_vec.at(i);
		}
		return os;
	}
}