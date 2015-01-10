#ifndef _AVL_TREE_TEST_
#define _AVL_TREE_TEST_

#include "gtest/gtest.h"
#include "../tree/AvlTree.h"

class CAvlTreeTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		tree.Insert(4);
		tree.Insert(2);
		tree.Insert(6);
		tree.Insert(1);
		tree.Insert(3);
		tree.Insert(5);
		tree.Insert(7);
		tree.Insert(16);
	}
	NsAvlTree::CAvlTree tree;
};
TEST_F(CAvlTreeTest, Insert)
{
	std::cout << tree << std::endl;
	tree.Insert(15);
	std::cout << tree << std::endl;
}

#endif