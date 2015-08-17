#include "RedBlackTree.h"

namespace NsRedBlackTree
{
	CRedBlackTree::CRedBlackTree(void)
	{
		this->root = NULL;
	}
	CRedBlackTree::~CRedBlackTree(void)
	{
		this->Clear();
	}
	bool CRedBlackTree::Clear(void)
	{
		this->ClearNode(this->root);
		return true;
	}
	bool CRedBlackTree::ClearNode(struct RedBlackNode *node)
	{
		if (node == NULL)
			return true;
		if (node->left)
		{
			this->ClearNode(node->left);
		}
		if (node->right)
		{
			this->ClearNode(node->right);
		}
		delete node;
		node = NULL;
		return true;
	}
	struct RedBlackNode *CRedBlackTree::NewNode(const int key)
	{
		struct RedBlackNode *new_node = new struct RedBlackNode;
		new_node->color = TreeRed;
		new_node->key = key;
		new_node->left = new_node->right = new_node->parent = NULL;
		return new_node;
	}
	bool CRedBlackTree::Insert(const int key)
	{
		struct RedBlackNode *x = this->root, *y = NULL;
		while (x != NULL)
		{
			y = x;
			if (key < x->key)
			{
				x = x->left;
			}
			else
			{
				x = x->right;
			}
		}
		struct RedBlackNode *new_node = this->NewNode(key);
		new_node->parent = y;
		if (y == NULL)
		{
			this->root = new_node;
		}
		else if (key < y->key)
		{
			y->left = new_node;
		}
		else
		{
			y->right = new_node;
		}
		return InsertFix(new_node);
	}
	bool CRedBlackTree::InsertFix(struct RedBlackNode *node)
	{
		if (node->parent == NULL || node->parent->parent == NULL)
			return true;
		struct RedBlackNode *y;
		while (node->parent->color == TreeRed)
		{
			if (node->parent == node->parent->parent->left)
			{
				y = node->parent->parent->right;
				if (y != NULL && y->color == TreeRed)
				{
					node->parent->color = TreeBlack;
					y->color = TreeBlack;
					node->parent->parent->color = TreeRed;
					node = node->parent->parent;
				}
				else if (node == node->parent->right)
				{
					node = node->parent;
					this->LeftRotate(node);
				}
				node->parent->color = TreeBlack;
				node->parent->parent->color = TreeRed;
				this->RightRotate(node->parent->parent);
			}
			else
			{
				y = node->parent->parent->left;
				if (y != NULL && y->color == TreeRed)	/// \bug if y == NULL?
				{
					node->parent->color = TreeBlack;
					y->color = TreeBlack;
					node->parent->parent->color = TreeRed;
					node = node->parent->parent;
				}
				else if (node == node->parent->left)
				{
					node = node->parent;
					this->RightRotate(node);
				}
				node->parent->color = TreeBlack;
				node->parent->parent->color = TreeRed;
				this->LeftRotate(node->parent->parent);
			}
		}
		this->root->color = TreeBlack;
		return true;
	}
	bool CRedBlackTree::LeftRotate(struct RedBlackNode *node)
	{
		struct RedBlackNode *y = node->right;
		node->right = y->left;
		if (y->left != NULL)	/// \bug if y->left == NULL?
			y->left->parent = y->left;
		y->parent = node->parent;
		if (node->parent == NULL)
		{
			this->root = y;
		}
		else if (node == node->parent->left)
		{
			node->parent->left = y;
		}
		else
		{
			node->parent->right = y;
		}
		y->left = node;
		node->parent = y;
		return true;
	}
	bool CRedBlackTree::RightRotate(struct RedBlackNode *node)
	{
		struct RedBlackNode *y = node->left;
		node->left = y->right;
		if (y->right != NULL)
			y->right->parent = y->right;
		y->parent = node->parent;
		if (node->parent == NULL)
		{
			this->root = y;
		}
		else if (node == node->parent->right)
		{
			node->parent->right = y;
		}
		else
		{
			node->parent->left = y;
		}
		y->right = node;
		node->parent = y;
		return true;
	}
	bool CRedBlackTree::Delete(const int key)
	{
		struct RedBlackNode *node/* = this->Find(key)*/;
		if (node)
		{
			return this->DeleteNode(node);
		}
		return false;
	}
	bool CRedBlackTree::DeleteNode(struct RedBlackNode *node)
	{
		struct RedBlackNode *x;
		if (node->left != NULL)
		{
			x = node->left;
		}
		else
		{
			x = node->right;
		}
		x->parent = node->parent;

		return true;
	}
	std::ostream &operator<< (std::ostream &os, struct RedBlackNode &node)
	{
		os << "( node " << node.key << " color " << node.color
			<< " left ";
		if (node.left)
			os << *(node.left);
		os << " right ";
		if (node.right)
			os << *(node.right);
		return os << " )";
	}
	std::ostream &operator<< (std::ostream &os, CRedBlackTree &tree)
	{
		os << "RedBlackTree ";
		if (tree.root == NULL)
		{
			os << "NULL";
			return os;
		}
		return os << *(tree.root);
	}
}