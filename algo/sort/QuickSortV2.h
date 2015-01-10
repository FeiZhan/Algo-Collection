#ifndef _QUICK_SORT_V2_H_
#define _QUICK_SORT_V2_H_

#include <iostream>
#include <vector>

namespace NsQuickSortV2
{
	class CQuickSortV2
	{
	public:
		CQuickSortV2 &operator<< (const int num);
		bool QuickSort(void);
		friend std::ostream &operator<< (std::ostream &os, CQuickSortV2 &sort);
	protected:
		bool SubQuickSort(const int left, const int right);
		bool Swap(const int pos1, const int pos2);
		int Median3(const int left, const int right);
	private:
		std::vector<int> num_vec;
	};
}

#endif