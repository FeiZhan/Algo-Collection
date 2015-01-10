#ifndef _DISJOINT_SET_TEST_
#define _DISJOINT_SET_TEST_

#include "gtest/gtest.h"
#include "../tree/DisjointSet.h"

class CDisjointSetTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		for (int i = 0; i < 10; ++ i)
			set << i << 19 - i;
	}
	NsDisjointSet::CDisjointSet set;
};
TEST_F(CDisjointSetTest, output)
{
	std::cout << set << std::endl;
}
TEST_F(CDisjointSetTest, FindKey)
{
	EXPECT_EQ(10, set.FindKey(5));
}
TEST_F(CDisjointSetTest, Find)
{
	EXPECT_EQ(10, set.Find(set.FindKey(5)));
}
TEST_F(CDisjointSetTest, SetUnion)
{
	set.SetUnion(1, 5);
	std::cout << set << std::endl;
	EXPECT_EQ(1, set.Find(set.FindKey(5)));
}

#endif