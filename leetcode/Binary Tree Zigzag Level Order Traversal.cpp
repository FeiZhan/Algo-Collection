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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> > ans;
		traverse(root, 0, ans);
		for (int i = 1; i < ans.size(); i += 2)
		{
			reverse(ans[i].begin(), ans[i].end());
		}
		return ans;
    }
    void traverse(const TreeNode *root, int level, vector<vector<int> > &ans)
    {
		if (NULL == root)
		{
			return;
		}
		while (ans.size() <= level)
		{
			ans.push_back(vector<int>());
		}
		ans[level].push_back(root->val);
		traverse(root->left, level + 1, ans);
		traverse(root->right, level + 1, ans);
	}
};
