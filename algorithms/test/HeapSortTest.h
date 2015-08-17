#ifndef _HEAP_SORT_TEST_
#define _HEAP_SORT_TEST_

#include "gtest/gtest.h"
#include "../sort/HeapSort.h"

TEST(HeapSortTest, BuildMaxHeap)
{
	NsHeapSort::CHeapSort heapsort;
	std::vector<int> num_vec;
	for (std::vector<int>::size_type i = 0; i < 20; ++ i)
	{
		num_vec.push_back(i);
	}
	heapsort.BuildMaxHeap(num_vec);
	heapsort.PrintHeap();
}
TEST(HeapSortTest, HeapSortTest)
{
	NsHeapSort::CHeapSort heapsort;
	std::vector<int> num_vec;
	for (std::vector<int>::size_type i = 0; i < 20; ++ i)
	{
		num_vec.push_back(i);
	}
	heapsort.BuildMaxHeap(num_vec);
	std::vector<int> ok_vec;
	for (std::vector<int>::size_type i = 0; i < 20; ++ i)
	{
		ok_vec.push_back(i);
	}
	EXPECT_EQ(ok_vec, heapsort.HeapSort());
	heapsort.PrintHeap();
}
TEST(HeapSortTest, IncreaseKey)
{
	NsHeapSort::CHeapSort heapsort;
	std::vector<int> num_vec;
	for (std::vector<int>::size_type i = 0; i < 20; ++ i)
	{
		num_vec.push_back(i);
	}
	heapsort.BuildMaxHeap(num_vec);
	heapsort.IncreaseKey(12, 21);
	heapsort.PrintHeap();
}
TEST(HeapSortTest, HeapInsert)
{
	NsHeapSort::CHeapSort heapsort;
	std::vector<int> num_vec;
	for (std::vector<int>::size_type i = 0; i < 20; ++ i)
	{
		num_vec.push_back(i);
	}
	heapsort.BuildMaxHeap(num_vec);
	heapsort.HeapInsert(20);
	heapsort.PrintHeap();
}

#endif