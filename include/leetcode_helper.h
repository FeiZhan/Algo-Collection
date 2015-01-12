#pragma once
#include <vector>
#include <queue>

// Definition for singly-linked list.
struct ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int x);
	virtual ~ListNode(void);
	friend ListNode &operator<< (ListNode &ln, int x);
	friend ListNode &operator<< (ListNode &ln, const std::vector<int> &list);
	friend std::ostream &operator<< (std::ostream &os, ListNode *ln);
};
ListNode::ListNode(int x) : val(x), next(NULL)
{}
ListNode::~ListNode(void)
{
	if (this->next)
	{
		delete this->next;
		this->next = NULL;
	}
}
ListNode &operator<< (ListNode &ln, int x)
{
	ListNode *current = &ln;
	if (NULL == current)
	{
		return ln;
	}
	while (current->next)
	{
		current = current->next;
	}
	current->next = new ListNode(x);
	return ln;
}
ListNode &operator<< (ListNode &ln, const std::vector<int> &list)
{
	ListNode *current = &ln;
	if (NULL == current)
	{
		return ln;
	}
	while (current->next)
	{
		current = current->next;
	}
	for (size_t i = 0; i < list.size(); ++i)
	{
		current->next = new ListNode(list[i]);
		current = current->next;
	}
	return ln;
}
std::ostream &operator<< (std::ostream &os, ListNode *ln)
{
	ListNode *current = ln;
	bool flag = true;
	while (current)
	{
		if (flag)
		{
			flag = false;
		}
		else
		{
			std::cout << ", ";
		}
		os << current->val;
		current = current->next;
	}
	return os;
}

// Definition for binary tree
struct TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x, TreeNode *l = NULL, TreeNode *r = NULL);
	virtual ~TreeNode(void);
	void load(const std::vector<int> &list);
	friend TreeNode &operator<< (TreeNode &tn, int x);
	friend TreeNode &operator<< (TreeNode &tn, const std::vector<int> &list);
	friend std::ostream &operator<< (std::ostream &os, TreeNode *tn);
protected:
	bool left_empty;
};
TreeNode::TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r)
{
	left_empty = NULL == left;
}
TreeNode::~TreeNode(void)
{
	if (this->left)
	{
		delete this->left;
		this->left = NULL;
	}
	if (this->right)
	{
		delete this->right;
		this->right = NULL;
	}
}
void TreeNode::load(const std::vector<int> &list)
{
	/*if (0 == list.size())
	{
	return;
	}
	this->val = list[0];
	std::queue<TreeNode *> q;
	q.push(this);
	for (size_t i = 1; i < list.size(); i += 2)
	{
	while (! q.empty())
	{
	TreeNode *current = q.top();
	q.pop();
	if (current->left && current->right)
	{
	continue;
	}
	if (NULL == current->left)
	}
	}*/
}
TreeNode &operator<< (TreeNode &tn, int x)
{
	return tn;
}
TreeNode &operator<< (TreeNode &tn, const std::vector<int> &list)
{
	return tn;
}
std::ostream &operator<< (std::ostream &os, TreeNode *tn)
{
	if (NULL != tn)
	{
		os << "(" << tn->val << ": " << tn->left << ", " << tn->right << ")";
	}
	else
	{
		os << "NULL";
	}
	return os;
}

// Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	virtual ~TreeLinkNode(void) {}
	friend std::ostream &operator<< (std::ostream &os, TreeLinkNode *tn);
};
std::ostream &operator<< (std::ostream &os, TreeLinkNode *tn)
{
	if (NULL != tn)
	{
		os << "(" << tn->val << ": " << tn->left << ", " << tn->right << ", -> ";
		if (tn->next) {
			os << tn->next->val << ")";
		}
		else {
			os << "NULL)";
		}
	}
	else
	{
		os << "NULL";
	}
	return os;
}

int _test_main(int argc, char *argv[])
{
	std::vector<int> list;
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	ListNode ln(0);
	ln << 1 << 2 << list;
	std::cout << &ln << std::endl;

	TreeNode tn(0, new TreeNode(1), new TreeNode(2));
	std::cout << &tn << std::endl;
	return 0;
}
