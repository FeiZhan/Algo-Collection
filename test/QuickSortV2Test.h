#ifndef _QUICK_SORT_V2_TEST_
#define _QUICK_SORT_V2_TEST_

#include "gtest/gtest.h"
#include "../sort/QuickSortV2.h"

class CQuickSortV2Test : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		sort << 3 << 5 << 1 << 4 << 2 << 0 << 6;
	}
	NsQuickSortV2::CQuickSortV2 sort;
};
TEST_F(CQuickSortV2Test, output)
{
	std::cout << sort << std::endl;
}
TEST_F(CQuickSortV2Test, sort)
{
	sort.QuickSort();
	std::cout << sort << std::endl;
}

#endif