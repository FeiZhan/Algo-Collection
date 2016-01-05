//@result 109 / 109 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 6.10% of cpp submissions.

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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
			return 0;
		}
        int sum = 0;
        if (NULL == root->left && NULL == root->right)
        {
			sum += root->val;
		}
        if (NULL != root->left)
        {
			root->left->val += root->val * 10;
			sum += sumNumbers(root->left);
		}
        if (NULL != root->right)
        {
			root->right->val += root->val * 10;
			sum += sumNumbers(root->right);
		}
		return sum;
    }
};
