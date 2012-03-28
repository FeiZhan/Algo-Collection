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
		/// \complexity O(N2)
		bool InsertionSort(void);
		/// \complexity O(N2)
		bool ShellSort(void);
		/// \complexity O(NlogN), require extra memory space
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