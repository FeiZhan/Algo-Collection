#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define DBG_ENABLED
#include "include/dbg-1.20/dbg.h"
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
	//Solution s;
	dbg::enable_all(dbg::info, true);
	     dbg::attach_ostream(dbg::info, std::cout);
     // now all 'info' messages go to cout

     dbg::out(dbg::info)    << "This is some info I want to print out\n";
     std::cout << "sdfsdfsdf";
     dbg::out(dbg::info) << dbg::indent()
                            << "This is output at 'tracing' level, indented "
                            << "to the same level as the current tracing "
                            << "indent.\n";
std::cout << std::endl;
	return 0;
}
