// recursive
// 2014-09-06
//@bug cannot make it iterative

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
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> ans;
		if (NULL == root)
		{
			return ans;
		}
		vector<int> left = postorderTraversal(root->left);
		ans.insert(ans.end(), left.begin(), left.end());
		vector<int> right = postorderTraversal(root->right);
		ans.insert(ans.end(), right.begin(), right.end());
		ans.push_back(root->val);
		return ans;
	}
};
