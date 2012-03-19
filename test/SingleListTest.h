#ifndef _SINGLE_LIST_TEST_
#define _SINGLE_LIST_TEST_

#include "gtest/gtest.h"
#include "../list/SingleList.h"

class CSingleListTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		list.PushBack(3);
		list.PushBack(5);
		list.PushBack(1);
		list.PushBack(6);
	}
	NsSingleList::CSingleList list;
};
TEST_F(CSingleListTest, output)
{
	std::cout << list << std::endl;
	list.Delete(1);
	std::cout << list << std::endl;
}
TEST_F(CSingleListTest, Find)
{
	EXPECT_EQ(1, list.Find(1)->key);
}

#endif