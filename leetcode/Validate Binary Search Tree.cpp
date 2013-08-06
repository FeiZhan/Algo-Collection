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
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min, max;
		return minMax(root, min, max);
    }
    bool minMax(const TreeNode *root, int &min, int &max)
    {
		min = INT_MIN;
		max = INT_MAX;
		if (NULL == root)
		{
			return true;
		}
		// default value of min, max
		min = max = root->val;
		if (NULL == root->left && NULL == root->right)
		{
			return true;
		}
		if (root->left)
		{
			int local_max;
			if (! minMax(root->left, min, local_max))
			{
				return false;
			}
			if (root->val <= local_max)
			{
				return false;
			}
		}
		if (root->right)
		{
			int local_min;
			if (! minMax(root->right, local_min, max))
			{
				return false;
			}
			if (root->val >= local_min)
			{
				return false;
			}
		}
		return true;
	}
};
