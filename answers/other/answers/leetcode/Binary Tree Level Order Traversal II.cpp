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
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		levelOrderBottom(root, 0);
		std::reverse(level_order.begin(), level_order.end());
		return level_order;
	}
	void levelOrderBottom(TreeNode *root, int level) {
		if (NULL == root) {
			return;
		}
		if (level_order.size() <= level) {
			level_order.resize(level + 1);
		}
		level_order[level].push_back(root->val);
		levelOrderBottom(root->left, level + 1);
		levelOrderBottom(root->right, level + 1);
	}
	vector<vector<int> > level_order;
};
