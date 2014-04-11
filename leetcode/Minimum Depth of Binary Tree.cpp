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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return minDepthRec(root, 0);
    }
    int minDepthRec(const TreeNode *node, int level)
    {
		if (NULL == node)
		{
			return level;
		}
		if (NULL == node->left && NULL == node->right)
		{
			return level + 1;
		} else if (NULL == node->left)
		{
			return minDepthRec(node->right, level + 1);
		} else if (NULL == node->right)
		{
			return minDepthRec(node->left, level + 1);
		}
		int left = minDepthRec(node->left, level + 1);
		int right = minDepthRec(node->right, level + 1);
		return (left < right) ? left : right;
	}
};

// accepted 2014-03-21
class Solution {
public:
	int minDepth(TreeNode *root) {
		if (NULL == root)
		{
			return 0;
		}
		if (NULL == root->left)
		{
			return 1 + minDepth(root->right);
		}
		if (NULL == root->right)
		{
			return 1 + minDepth(root->left);
		}
		int left = minDepth(root->left);
		int right = minDepth(root->right);
		return 1 + (left < right ? left : right);
	}
};