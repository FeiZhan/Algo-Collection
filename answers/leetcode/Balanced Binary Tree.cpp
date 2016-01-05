//@result 226 / 226 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 84.69% of cpp submissions.

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
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return depth(root) >= 0;
    }
    int depth(const TreeNode *root)
    {
        if (NULL == root)
        {
			return 0;
		} else if (NULL == root->left && NULL == root->right)
        {
			return 1;
		} else if (NULL == root->left)
		{
			int d = depth(root->right);
			if (d < 0 || d > 1)
			{
				return -1;
			} else
			{
				return d + 1;
			}
		} else if (NULL == root->right)
		{
			int d = depth(root->left);
			if (d < 0 || d > 1)
			{
				return -1;
			} else
			{
				return d + 1;
			}
		} else
		{
			int left = depth(root->left);
			int right = depth(root->right);
			if (left < 0 || right < 0 || left - right > 1 || left - right < -1)
			{
				return -1;
			} else
			{
				return (left >= right) ? left + 1 : right + 1;
			}
		}
	}
};
