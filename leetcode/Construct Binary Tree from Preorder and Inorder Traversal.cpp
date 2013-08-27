// copied from leetcode
// if copy smaller vector, MLE

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    TreeNode *build(const std::vector<int> &preorder, const int pre_first, const int pre_last, const std::vector<int> &inorder, const int in_first, const int in_last)
    {
		if (in_first > in_last)
		{
			return NULL;
		}
		TreeNode* root = new TreeNode(preorder[pre_first]);
		if (in_first == in_last)
		{
			return root;
		}
		const size_t r_in = std::distance(inorder.begin(), std::find(inorder.begin() + in_first, inorder.begin() + in_last, root->val));
		const size_t size_left = r_in - in_first;
		root->left = build(preorder, pre_first + 1, pre_first + size_left - 1, inorder, in_first, r_in - 1);
		root->right = build(preorder, pre_first + size_left + 1, pre_last, inorder, r_in + 1, in_last);
		return root;
	}
	void output(const TreeNode *now)
	{
		if (NULL == now)
		{
			return;
		}
		std::cout << now->val << " : ( ";
		output(now->left);
		output(now->right);
		std::cout << " ) ";
	}
};
int main()
{
	Solution s;
	std::vector<int> preorder, inorder;
	//[1,2,3,4], [1,2,3,4]
	//[1,2], [2,1]
	preorder.clear();
	inorder.clear();
	preorder.push_back(1);
	preorder.push_back(2);
	inorder.push_back(2);
	inorder.push_back(1);
	s.output(s.buildTree(preorder, inorder));
	return 0;
}
