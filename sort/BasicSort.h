#ifndef _BASIC_SORT_
#define _BASIC_SORT_

#include <iostream>
#include <vector>

namespace NsBasicSort
{
	class CBasicSort
	{
	public:
		CBasicSort &operator<< (const int num);
		bool InsertionSort(void);
		bool ShellSort(void);
		bool MergeSort(void);
		friend std::ostream &operator<< (std::ostream &os
			, const CBasicSort &sort);
	protected:
		bool MergeSortRec(const int left, const int right);
		bool Merge(const int left, const int mid, const int right);
	private:
		std::vector<int> num;
	};
}

#endif