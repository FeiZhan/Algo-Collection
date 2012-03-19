#ifndef _B_TREE_
#define _B_TREE_

#include <iostream>
#include <vector>
#include <set>

namespace NsBTree
{
	struct BNode
	{
		std::set<int> key;
		bool is_leaf;
		std::vector<struct BNode*> child;
	};
	class CBTree
	{
	public:
		CBTree(void);
		~CBTree(void);
		bool Clear(void);
		bool Insert(const int key);
	protected:
		bool ClearNode(struct BNode *node);
		struct BNode *NewNode(void);
		bool SplitChild(struct BNode *x, const int i, struct BNode *y);
		//bool InsertNonfull(struct BNode *x, const int key);
	private:
		struct BNode *root;
		int min_degree;
	};
}

#endif