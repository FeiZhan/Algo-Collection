#ifndef _GTEST_TEST_
#define _GTEST_TEST_

#include "gtest/gtest.h"
int factorial(int num)
{
	return (num <= 1) ? 1 : num * factorial(num - 1);
}
TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
	for (int i = 0; i < 2; ++ i)
	{
		EXPECT_EQ(0, factorial(i)) << "something wrong?";
	}
}

#endif