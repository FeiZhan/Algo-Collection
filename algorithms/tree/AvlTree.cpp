#include "AvlTree.h"

namespace NsAvlTree
{
	CAvlTree::CAvlTree(void)
	{
		this->root = NULL;
	}
	CAvlTree::~CAvlTree(void)
	{
		this->Clear();
	}
	bool CAvlTree::Clear(void)
	{
		return this->ClearNode(this->root);
	}
	bool CAvlTree::ClearNode(struct AvlTreeNode *node)
	{
		if (node)
		{
			this->ClearNode(node->left);
			this->ClearNode(node->right);
			delete node;
			node = NULL;
		}
		return true;
	}
	int CAvlTree::Height(const struct AvlTreeNode *pos)
	{
		if (pos == NULL)
			return -1;
		else
			return pos->height;
	}
	bool CAvlTree::Insert(const int key)
	{
		this->root = this->InsertNode(key, this->root);
		return true;
	}
	struct AvlTreeNode *CAvlTree::InsertNode(const int key
		, struct AvlTreeNode *node)
	{
		if (node == NULL)
		{
			node = new struct AvlTreeNode;
			if (node == NULL)
			{
				std::cerr << "out of memory" << std::endl;
			}
			else
			{
				node->key = key;
				node->height = 0;
				node->left = node->right = NULL;
			}
		}
		else if (key < node->key)
		{
			node->left = this->InsertNode(key, node->left);
			if (this->Height(node->left) - this->Height(node->right) >= 2)
			{
				if (key < node->left->key)
				{
					node = SingleRotateWithLeft(node);
				}
				else
				{
					node = DoubleRotateWithLeft(node);
				}
			}
		}
		else if (key > node->key)
		{
			node->right = this->InsertNode(key, node->right);
			if (this->Height(node->right) - this->Height(node->left) >= 2)
			{
				if (key > node->right->key)
					node = SingleRotateWithRight(node);
				else
					node = DoubleRotateWithRight(node);
			}
		}
		/// \note else key is in the tree already, we will do nothing.
		node->height = std::max(this->Height(node->left)
			, this->Height(node->right)) + 1;
		return node;
	}
	struct AvlTreeNode *CAvlTree::SingleRotateWithLeft(struct AvlTreeNode *node)
	{
		struct AvlTreeNode *node2;
		node2 = node->left;
		node->left = node2->right;
		node2->right = node;
		node->height = std::max(this->Height(node->left)
			, this->Height(node->right)) + 1;
		node2->height = std::max(this->Height(node2->left)
			, node->height) + 1;
		return node2;
	}
	struct AvlTreeNode *CAvlTree::SingleRotateWithRight(struct AvlTreeNode *node)
	{
		struct AvlTreeNode *node2;
		node2 = node->right;
		node->right = node2->left;
		node2->left = node;
		node->height = std::max(this->Height(node->left)
			, this->Height(node->right)) + 1;
		node2->height = std::max(this->Height(node2->right)
			, node->height) + 1;
		return node2;
	}
	struct AvlTreeNode *CAvlTree::DoubleRotateWithLeft(struct AvlTreeNode *node)
	{
		node->left = this->SingleRotateWithRight(node->left);
		return this->SingleRotateWithLeft(node);
	}
	struct AvlTreeNode *CAvlTree::DoubleRotateWithRight(struct AvlTreeNode *node)
	{
		node->right = this->SingleRotateWithLeft(node->right);
		return this->SingleRotateWithRight(node);
	}
	std::ostream &operator<< (std::ostream &os, const struct AvlTreeNode &node)
	{
		/// \note preorder traversal
		os << "( node " << node.key << " left ";
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
	std::ostream &operator<< (std::ostream &os, const CAvlTree &tree)
	{
		os << "AvlTree ";
		if (tree.root == NULL)
		{
			os << "NULL";
			return os;
		}
		return os << *(tree.root);
	}
}