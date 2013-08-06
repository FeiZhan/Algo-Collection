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
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (NULL == root || isSym(root->left, root->right))
		{
			return true;
		} else
		{
			return false;
		}
    }
    bool isSym(const TreeNode *left, const TreeNode *right)
    {
		if (NULL == left && NULL == right)
		{
			return true;
		} else if (NULL == left || NULL == right)
		{
			return false;
		}
		if (left->val == right->val && isSym(left->left, right->right) && isSym(left->right, right->left))
		{
			return true;
		}
		return false;
	}
};
