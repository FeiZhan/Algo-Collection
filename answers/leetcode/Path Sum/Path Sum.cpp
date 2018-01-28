//@result 114 / 114 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 12.82% of cpp submissions.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
			return false;
		}
		if (sum == root->val && NULL == root->left && NULL == root->right)
		{
			return true;
		}
		if (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val))
		{
			return true;
		}
		return false;
    }
};
