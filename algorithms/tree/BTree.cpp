#include "BTree.h"

namespace NsBTree
{
	CBTree::CBTree(void)
	{
		this->root = NULL;
		min_degree = 7;
	}
	CBTree::~CBTree(void)
	{
		this->Clear();
	}
	bool CBTree::Clear(void)
	{
		return this->ClearNode(this->root);
	}
	bool CBTree::ClearNode(struct BNode *node)
	{
		if (node == NULL)
			return true;
		for (int i = 0; i < node->child.size(); ++ i)
		{
			this->ClearNode(node->child.at(i));
		}
		delete node;
		node = NULL;
		return true;
	}
	struct BNode *CBTree::NewNode(void)
	{
		struct BNode *node = new struct BNode;
		node->is_leaf = true;
		return node;
	}
	bool CBTree::Insert(const int key)
	{
		struct BNode *r = this->root, *s;
		if (r->key.size() == 2 * this->min_degree - 1)
		{
			s = this->NewNode();
			root = s;
			s->is_leaf = false;
			s->child.push_back(r);
			this->SplitChild(s, 1, r);
			//this->InsertNonfull(s, key);
		}
		else
		{
			//this->InsertNonfull(r, key);
		}
		return true;
	}
	bool CBTree::SplitChild(struct BNode *x, const int i, struct BNode *y)
	{
		//struct BNode *z = this->NewNode();
		//z->is_leaf = y->is_leaf;
		//for (int j = 1; j <= this->min_degree - 1; ++ j)
		//{
		//	/// \todo wrong
		//	z->key.insert(*(y->key.begin() + j + this->min_degree));
		//}
		//if (! y->is_leaf)
		//{
		//	for (int j = 1; j <= this->min_degree; ++ j)
		//	{
		//		z->child.push_back(y->child.at(j + this->min_degree));
		//	}
		//}
		//for (int j = x->key.size(); j >= i + 1; -- j)
		//{
		//	x->child[j + 1] = x->child.at(j);
		//}
		//x->child[i + 1] = z;
		//for (int j = x->key.size(); j >= i; ++ j)
		//{
		//	x->key[j + 1] = *(x->key.begin() + j);
		//}
		//x->key[i] = y->key.at(this->min_degree);
		return true;
	}
}