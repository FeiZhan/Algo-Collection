/// \cite CLRS

#ifndef _RED_BLACK_TREE_
#define _RED_BLACK_TREE_

#include <iostream>

namespace NsRedBlackTree
{
	enum TreeColor
	{
		TreeRed,
		TreeBlack
	};
	struct RedBlackNode
	{
		int key;
		enum TreeColor color;
		struct RedBlackNode *left, *right, *parent;
		friend std::ostream &operator<< (std::ostream &os
			, struct RedBlackNode &node);
	};
	class CRedBlackTree
	{
	public:
		CRedBlackTree(void);
		~CRedBlackTree(void);
		bool Clear(void);
		bool Insert(const int key);
		bool Delete(const int key);
		friend std::ostream &operator<< (std::ostream &os, CRedBlackTree &tree);
	protected:
		bool ClearNode(struct RedBlackNode *node);
		struct RedBlackNode *NewNode(const int key);
		bool InsertFix(struct RedBlackNode *node);
		bool LeftRotate(struct RedBlackNode *node);
		bool RightRotate(struct RedBlackNode *node);
		bool DeleteNode(struct RedBlackNode *node);
	private:
		struct RedBlackNode *root;
	};
}

#endif