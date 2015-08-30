#ifndef _RED_BLACK_TREE_TEST_
#define _RED_BLACK_TREE_TEST_

#include "gtest/gtest.h"
#include "../tree/RedBlackTree.h"

class CRedBlackTreeTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		rbtree.Insert(1);
		rbtree.Insert(2);
		rbtree.Insert(3);
	}
	NsRedBlackTree::CRedBlackTree rbtree;
};
TEST_F(CRedBlackTreeTest, output)
{
	std::cout << rbtree << std::endl;
	SUCCEED();
}

#endif