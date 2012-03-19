#ifndef _STACK_TEST_
#define _STACK_TEST_

#include "gtest/gtest.h"
#include "../list/Stack.h"

class CStackTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		stack.Push(3);
		stack.Push(1);
		stack.Push(5);
		stack.Push(4);
	}
	NsStack::CStack stack;
};
TEST_F(CStackTest, output)
{
	std::cout << stack << std::endl;
	EXPECT_EQ(4, stack.Top());
	stack.Pop();
	std::cout << stack << std::endl;
}

#endif