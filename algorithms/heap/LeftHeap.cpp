#include "LeftHeap.h"

namespace NsLeftHeap
{
	CLeftHeap::CLeftHeap(void)
	{
		this->root = NULL;
	}
	CLeftHeap::~CLeftHeap(void)
	{
		while (this->root)
			this->DeleteMin();
	}
	bool CLeftHeap::Empty(void)
	{
		return this->root == NULL;
	}
	bool CLeftHeap::Insert(const int key)
	{
		this->root = InsertNode(key, this->root);
		return true;
	}
	struct LeftHeapNode *CLeftHeap::InsertNode(const int key
		, struct LeftHeapNode *node)
	{
		struct LeftHeapNode *new_node = new struct LeftHeapNode;
		if (new_node == NULL)
		{
			std::cerr << "out of memory" << std::endl;
			return NULL;
		}
		new_node->key = key;
		new_node->npl = 0;
		new_node->left = new_node->right = NULL;
		node = this->Merge(node, new_node);
		return node;
	}
	int CLeftHeap::DeleteMin(void)
	{
		if (this->root == NULL)
		{
			std::cerr << "left heap is empty" << std::endl;
			return -1;
		}
		struct LeftHeapNode *node = this->root;
		this->root = this->Merge(this->root->left, this->root->right);
		int ret = node->key;
		delete node;
		return ret;
	}
	struct LeftHeapNode *CLeftHeap::Merge(struct LeftHeapNode *node1
			, struct LeftHeapNode *node2)
	{
		if (node1 == NULL)
			return node2;
		if (node2 == NULL)
			return node1;
		if (node1->key < node2->key)
		{
			return this->MergeNode(node1, node2);
		}
		else
		{
			return this->MergeNode(node2, node1);
		}
	}
	struct LeftHeapNode *CLeftHeap::MergeNode(struct LeftHeapNode *node1
			, struct LeftHeapNode *node2)
	{
		if (node1->left == NULL)
		{
			node1->left = node2;
		}
		else
		{
			node1->right = this->Merge(node1->right, node2);
			if (node1->left->npl < node1->right->npl)
			{
				this->SwapChildren(node1);
			}
			node1->npl = node1->right->npl + 1;
		}
		return node1;
	}
	bool CLeftHeap::SwapChildren(struct LeftHeapNode *node)
	{
		struct LeftHeapNode *tmp = node->left;
		node->left = node->right;
		node->right = tmp;
		return true;
	}
	std::ostream &operator<< (std::ostream &os, const struct LeftHeapNode &node)
	{
		/// \note preorder traversal
		os << "( node " << node.key << " npl " << node.npl << " left ";
		if (node.left)
			os << *(node.left);
		else
			os << "NULL";
		os << " right ";
		if (node.right)
			os << *(node.right);
		else
			os << "NULL";
		return os << " )";
	}
	std::ostream &operator<< (std::ostream &os, const CLeftHeap &heap)
	{
		os << "LeftHeapNode ";
		if (heap.root == NULL)
		{
			os << "NULL";
			return os;
		}
		return os << *(heap.root);
	}
}