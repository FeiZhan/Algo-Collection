/// from DSAA
/// \bug CLRS is different from this

#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

#include <iostream>

namespace NsBinSearchTree
{
	struct BinTreeNode
	{
		int key;
		struct BinTreeNode *left, *right;
		friend std::ostream &operator<< (std::ostream &os
			, const struct BinTreeNode &node);
	};
	class CBinSearchTree
	{
	public:
		CBinSearchTree(void);
		~CBinSearchTree(void);
		virtual bool Clear(void);
		/// \note the core operation of BinSearchTree.
		/// The Average Time Complexity is O(log N).
		struct BinTreeNode *Find(const int key);
		struct BinTreeNode *FindMin(void);
		struct BinTreeNode *FindMax(void);
		bool Insert(const int key);
		bool Delete(const int key);
		/// \note this CBinSearchTree should be a reference.
		friend std::ostream &operator<< (std::ostream &os
			, const CBinSearchTree &tree);
	protected:
		virtual bool ClearNode(struct BinTreeNode *node);
		struct BinTreeNode *FindNode(const int key
			, struct BinTreeNode *node);
		struct BinTreeNode *FindMinNode(struct BinTreeNode *node);
		struct BinTreeNode *InsertNode(const int key, struct BinTreeNode *node);
		struct BinTreeNode *DeleteNode(const int key, struct BinTreeNode *node);
	private:
		struct BinTreeNode *root;
	};
}

#endif