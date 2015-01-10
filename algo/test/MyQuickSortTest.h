#ifndef _MY_QUICK_SORT_TEST_
#define _MY_QUICK_SORT_TEST_

#include <iostream>
#include "../main/param.h"
#include "../sort/QuickSort.h"

bool MyQuickSortTest(void)
{
	for (int i = 0; i < TEST_HEADING_LEN; ++ i)
	{
		std::cout << TEST_HEADING;
	}
	std::cout << "Quick Sort Test" << std::endl;
	NsQuickSort::CQuickSort qsort;
	std::vector<int> num_vec;
	for (std::vector<int>::size_type i = 0; i < 10; ++ i)
	{
		num_vec.push_back(i);
		num_vec.push_back(19 - i);
	}
	if (qsort.QuickSort(num_vec))
	{
		std::cout << "ok"<< std::endl;
	}
	else
	{
		std::cout << "fail" << std::endl;
	}
	std::cout << std::endl;
	for (std::vector<int>::size_type i = 0; i < num_vec.size(); ++ i)
	{
		std::cout << num_vec.at(i) << std::endl;
	}
	return true;
}
#endif