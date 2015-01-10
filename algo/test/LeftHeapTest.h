#ifndef _LEFT_HEAP_TEST_
#define _LEFT_HEAP_TEST_

#include "gtest/gtest.h"
#include "../heap/LeftHeap.h"

class CLeftHeapTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		for (int i = 0; i < 10; ++ i)
		{
			heap.Insert(i);
			heap.Insert(19 - i);
		}
	}
	NsLeftHeap::CLeftHeap heap;
};
TEST_F(CLeftHeapTest, output)
{
	std::cout << heap << std::endl;
	SUCCEED();
}
TEST_F(CLeftHeapTest, DeleteMin)
{
	while (! heap.Empty())
	{
		std::cout << heap.DeleteMin() << " ";
	}
	std::cout << std::endl;
	SUCCEED();
}

#endif