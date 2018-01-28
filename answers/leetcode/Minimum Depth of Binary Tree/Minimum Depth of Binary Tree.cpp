// accepted 2014-03-21
//@result 41 / 41 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 5.11% of cpp submissions.

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
