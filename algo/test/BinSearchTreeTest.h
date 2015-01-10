#ifndef _BIN_SEARCH_TREE_TEST_
#define _BIN_SEARCH_TREE_TEST_

#include "gtest/gtest.h"
#include "../tree/BinSearchTree.h"

class CBinSearchTreeTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		tree.Insert(3);
		tree.Insert(1);
		tree.Insert(5);
		tree.Insert(4);
	}
	NsBinSearchTree::CBinSearchTree tree;
};
TEST_F(CBinSearchTreeTest, output)
{
	std::cout << tree << std::endl;
}
TEST_F(CBinSearchTreeTest, Find)
{
	EXPECT_EQ(5, tree.Find(5)->key);
}
TEST_F(CBinSearchTreeTest, FindMin)
{
	EXPECT_EQ(1, tree.FindMin()->key);
}
TEST_F(CBinSearchTreeTest, FindMax)
{
	EXPECT_EQ(5, tree.FindMax()->key);
}
TEST_F(CBinSearchTreeTest, Delete)
{
	tree.Delete(5);
	std::cout << tree << std::endl;
}

#endif