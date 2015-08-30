/// from DSAA

#ifndef _AVL_TREE_
#define _AVL_TREE_

#include <iostream>
#include "BinSearchTree.h"

namespace NsAvlTree
{
	struct AvlTreeNode
	{
		int key, height;
		struct AvlTreeNode *left, *right;
		friend std::ostream &operator<< (std::ostream &os
			, const struct AvlTreeNode &node);
	};
	class CAvlTree
	{
	public:
		CAvlTree(void);
		~CAvlTree(void);
		bool Clear(void);
		int Height(const struct AvlTreeNode *pos);
		bool Insert(const int key);
		friend std::ostream &operator<< (std::ostream &os
			, const CAvlTree &tree);
	protected:
		bool ClearNode(struct AvlTreeNode *node);
		struct AvlTreeNode *InsertNode(const int key, struct AvlTreeNode *node);
		struct AvlTreeNode *SingleRotateWithLeft(struct AvlTreeNode *node);
		struct AvlTreeNode *SingleRotateWithRight(struct AvlTreeNode *node);
		struct AvlTreeNode *DoubleRotateWithLeft(struct AvlTreeNode *node);
		struct AvlTreeNode *DoubleRotateWithRight(struct AvlTreeNode *node);
	private:
		struct AvlTreeNode *root;
	};
}

#endif