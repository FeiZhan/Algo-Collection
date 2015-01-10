#include "BinSearchTree.h"

namespace NsBinSearchTree
{
	CBinSearchTree::CBinSearchTree(void)
	{
		root = NULL;
	}
	CBinSearchTree::~CBinSearchTree(void)
	{
		this->Clear();
	}
	bool CBinSearchTree::Clear(void)
	{
		std::cout << "clear " << this->root->key << std::endl;
		return this->ClearNode(this->root);
	}
	bool CBinSearchTree::ClearNode(struct BinTreeNode *node)
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
	struct BinTreeNode *CBinSearchTree::Find(const int key)
	{
		return this->FindNode(key, this->root);
	}
	struct BinTreeNode *CBinSearchTree::FindNode(const int key
		, struct BinTreeNode *node)
	{
		if (node == NULL)
			return NULL;
		if (key < node->key)
		{
			return this->FindNode(key, node->left);
		}
		else if (key > node->key)
		{
			return this->FindNode(key, node->right);
		}
		else
		{
			return node;
		}
	}
	struct BinTreeNode *CBinSearchTree::FindMin(void)
	{
		return FindMinNode(this->root);
	}
	struct BinTreeNode *CBinSearchTree::FindMinNode(struct BinTreeNode *node)
	{
		if (node == NULL)
			return NULL;
		else if (node->left == NULL)
			return node;
		else
			return this->FindMinNode(node->left);
	}
	struct BinTreeNode *CBinSearchTree::FindMax(void)
	{
		struct BinTreeNode *node = this->root;
		if (node)
		{
			while (node->right)
			{
				node = node->right;
			}
		}
		return node;
	}
	bool CBinSearchTree::Insert(const int key)
	{
		/// \note almost wrong
		this->root = this->InsertNode(key, this->root);
		return true;
	}
	struct BinTreeNode *CBinSearchTree::InsertNode(const int key
		, struct BinTreeNode *node)
	{
		if (node == NULL)
		{
			node = new struct BinTreeNode;
			if (node == NULL)
			{
				std::cerr << "out of memory" << std::endl;
				return NULL;
			}
			node->key = key;
			node->left = node->right = NULL;
		}
		else if (key < node->key)
		{
			node->left = this->InsertNode(key, node->left);
		}
		else if (key > node->key)
		{
			node->right = this->InsertNode(key, node->right);
		}
		return node;
	}
	bool CBinSearchTree::Delete(const int key)
	{
		this->DeleteNode(key, this->root);
		return true;
	}
	struct BinTreeNode *CBinSearchTree::DeleteNode(const int key
		, struct BinTreeNode *node)
	{
		if (node == NULL)
		{
			std::cerr << "element not found" << std::endl;
		}
		else if (key < node->key)
		{
			node->left = this->DeleteNode(key, node->left);
		}
		else if (key > node->key)
		{
			node->right = this->DeleteNode(key, node->right);
		}
		else if (node->left && node->right)
		{
			/// \bug not balance
			struct BinTreeNode *tmp = this->FindMinNode(node->right);
			node->key = tmp->key;
			node->right = this->DeleteNode(node->key, node->right);
		}
		else
		{
			struct BinTreeNode *tmp = node;
			if (node->left == NULL)
				node = node->right;
			else if (node->right == NULL)
				node = node->left;
			delete tmp;
		}
		return node;
	}
	std::ostream &operator<< (std::ostream &os, const struct BinTreeNode &node)
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
	std::ostream &operator<< (std::ostream &os, const CBinSearchTree &tree)
	{
		os << "BinSearchTree ";
		if (tree.root == NULL)
		{
			os << "NULL";
			return os;
		}
		return os << *(tree.root);
	}
}