//@result 192 / 192 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 13.01% of cpp submissions.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 2014-04-11
class Solution {
public:
	bool isSymmetric(TreeNode *root) {
		if (NULL == root)
		{
			return true;
		}
		return isSymmetric(root->left, root->right);
	}
	bool isSymmetric(TreeNode *left, TreeNode *right)
	{
		if (NULL == left || NULL == right)
		{
			return NULL == left && NULL == right;
		}
		return left->val == right->val && isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	}
};
