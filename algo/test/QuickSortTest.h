#ifndef _QUICK_SORT_TEST_
#define _QUICK_SORT_TEST_

#include "gtest/gtest.h"
#include "../sort/QuickSort.h"

TEST(quicksorttest, maintest)
{
	NsQuickSort::CQuickSort qsort;
	std::vector<int> num_vec;
	for (std::vector<int>::size_type i = 0; i < 10; ++ i)
	{
		num_vec.push_back(i);
		num_vec.push_back(19 - i);
	}
	qsort.QuickSort(num_vec);
	std::vector<int> ok_vec;
	for (std::vector<int>::size_type i = 0; i < 20; ++ i)
	{
		ok_vec.push_back(i);
	}
	EXPECT_EQ(ok_vec, num_vec);
	std::cout << "quick sort content:";
	for (std::vector<int>::size_type i = 0; i < num_vec.size(); ++ i)
	{
		std::cout << " " << num_vec.at(i);
	}
	std::cout << std::endl;
}

#endif