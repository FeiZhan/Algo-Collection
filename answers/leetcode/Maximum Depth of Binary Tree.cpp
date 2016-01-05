//@result 38 / 38 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 11.97% of cpp submissions.

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
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
			return 0;
		}
		int max = 1;
		if (root->left)
		{
			max = maxDepth(root->left) + 1;
		}
		if (root->right)
		{
			int right = maxDepth(root->right) + 1;
			max = (max < right) ? right : max;
		}
		return max;
    }
};
