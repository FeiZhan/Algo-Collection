#ifndef _RED_BLACK_TREE_TEST_
#define _RED_BLACK_TREE_TEST_

#include "gtest/gtest.h"
#include "../tree/RedBlackTree.h"

TEST(RedBlackTreeTest, Insert)
{
	NsRedBlackTree::CRedBlackTree rbtree;
	rbtree.Insert(1);
	rbtree.Insert(2);
	rbtree.Insert(3);
	rbtree.Traverse();
}

#endif