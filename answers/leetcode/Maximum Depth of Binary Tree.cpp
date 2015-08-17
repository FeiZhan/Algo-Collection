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
