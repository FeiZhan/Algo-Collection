#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;


//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	void print(void)
	{
		std::cout << this->val << ", ";
		if (NULL != next)
		{
			next->print();
		}
	}
};


int main(int argc, char *argv[])
{
	Solution s;
	return 0;
}
