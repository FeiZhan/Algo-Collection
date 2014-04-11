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
// 2014-04-11
class Solution {
public:
	bool isValidBST(TreeNode *root) {
		if (NULL == root)
		{
			return true;
		}
		TreeNode *temp = root->left;
		while (NULL != temp && NULL != temp->right)
		{
			temp = temp->right;
		}
		if (NULL != temp && temp->val >= root->val)
		{
			return false;
		}
		temp = root->right;
		while (NULL != temp && NULL != temp->left)
		{
			temp = temp->left;
		}
		if (NULL != temp && temp->val <= root->val)
		{
			return false;
		}
		return isValidBST(root->left) && isValidBST(root->right);
	}
};