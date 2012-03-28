#ifndef _BIN_HEAP_TEST_
#define _BIN_HEAP_TEST_

#include "gtest/gtest.h"
#include "../heap/BinHeap.h"

class CBinHeapTest : public ::testing::Test
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
	NsBinHeap::CBinHeap heap;
};
TEST_F(CBinHeapTest, output)
{
	std::cout << heap << std::endl;
}
TEST_F(CBinHeapTest, DeleteMin)
{
	while (! heap.Empty())
	{
		std::cout << heap.DeleteMin() << " ";
	}
	std::cout << std::endl;
}

#endif