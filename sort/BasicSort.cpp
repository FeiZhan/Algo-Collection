#include "BasicSort.h"

namespace NsBasicSort
{
	CBasicSort &CBasicSort::operator<< (const int num)
	{
		this->num.push_back(num);
		return *this;
	}
	bool CBasicSort::InsertionSort(void)
	{
		int tmp, j;
		for (int i = 0; i < this->num.size(); ++ i)
		{
			tmp = this->num.at(i);
			for (j = i - 1; j >= 0 && this->num.at(j) > tmp; -- j)
			{
				this->num[j + 1] = this->num[j];
			}
			this->num[j + 1] = tmp;
		}
		return true;
	}
	bool CBasicSort::ShellSort(void)
	{
		int tmp, j;
		for (int inc = this->num.size() / 2; inc > 0; inc /= 2)
		{
			for (int i = inc; i < this->num.size(); ++ i)
			{
				tmp = this->num.at(i);
				for (j = i - inc; j >= 0 && tmp < this->num.at(j)
					; j -= inc)
				{
					this->num[j + inc] = this->num.at(j);
				}
				this->num[j + inc] = tmp;
			}
		}
		return true;
	}
	bool CBasicSort::MergeSort(void)
	{
		return this->MergeSortRec(0, this->num.size() - 1);
	}
	bool CBasicSort::MergeSortRec(const int left, const int right)
	{
		if (left < right)
		{
			int center = (left + right) / 2;
			this->MergeSortRec(left, center);
			this->MergeSortRec(center + 1, right);
			this->Merge(left, center + 1, right);
		}
		return true;
	}
	bool CBasicSort::Merge(const int left, const int mid, const int right)
	{
		int lptr = left, rptr = mid;
		std::vector<int> tmp;
		while (lptr <= mid - 1 && rptr <= right)
		{
			if (this->num.at(lptr) <= this->num.at(rptr))
			{
				tmp.push_back(this->num.at(lptr));
				lptr ++;
			}
			else
			{
				tmp.push_back(this->num.at(rptr));
				rptr ++;
			}
		}
		while (lptr <= mid - 1)
		{
			tmp.push_back(this->num.at(lptr));
			lptr ++;
		}
		while (rptr <= right)
		{
			tmp.push_back(this->num.at(rptr));
			rptr ++;
		}
		for (int i = 0; i < tmp.size(); ++ i)
		{
			this->num[right - i] = tmp.at(tmp.size() - i - 1);
		}
	
		return true;
	}
	std::ostream &operator<< (std::ostream &os, const CBasicSort &sort)
	{
		os << "BasicSort";
		for (int i = 0; i < sort.num.size(); ++ i)
		{
			os << " " << sort.num.at(i);
		}
		return os;
	}
}