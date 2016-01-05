// 2015-1-1
//@result 34 / 34 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 79.94% of cpp submissions.


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
	vector<vector<int> > levelOrder(TreeNode *root) {
		ans.clear();
		levelOrder(root, 0);
		return ans;
	}
	void levelOrder(TreeNode *root, int level) {
		if (NULL == root) {
			return;
		}
		if (ans.size() <= level) {
			ans.resize(level + 1);
		}
		ans[level].push_back(root->val);
		levelOrder(root->left, level + 1);
		levelOrder(root->right, level + 1);
	}
	vector<vector<int> > ans;
};
