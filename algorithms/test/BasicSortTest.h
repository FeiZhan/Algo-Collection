#ifndef _BASIC_SORT_TEST_
#define _BASIC_SORT_TEST_

#include "gtest/gtest.h"
#include "../sort/BasicSort.h"

TEST(BasicSortTest, InsertionSort)
{
	NsBasicSort::CBasicSort sort;
	for (int i = 0; i < 10; ++ i)
	{
		sort << i;
		sort << 19 - i;
	}
	sort.InsertionSort();
	std::cout << sort << std::endl;
}
TEST(BasicSortTest, ShellSort)
{
	NsBasicSort::CBasicSort sort;
	for (int i = 0; i < 10; ++ i)
	{
		sort << i;
		sort << 19 - i;
	}
	sort.ShellSort();
	std::cout << sort << std::endl;
}
TEST(BasicSortTest, MergeSort)
{
	NsBasicSort::CBasicSort sort;
	for (int i = 0; i < 10; ++ i)
	{
		sort << i;
		sort << 19 - i;
	}
	sort.MergeSort();
	std::cout << sort << std::endl;
}

#endif