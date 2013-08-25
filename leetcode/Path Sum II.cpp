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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> > ans;
		if (NULL == root)
		{
			return ans;
		}
		vector<int> path;
		path.push_back(root->val);
		calc(root, path, root->val, sum, ans);
		return ans;
    }
    void calc(const TreeNode *now, const vector<int> &path, int val, int sum, vector<vector<int> > &ans)
    {
		if (NULL == now)
		{
			return;
		}
		if (val == sum && NULL == now->left && NULL == now->right)
		{
			ans.push_back(path);
			return;
		}
		if (now->left)
		{
			vector<int> next = path;
			next.push_back(now->left->val);
			calc(now->left, next, val + now->left->val, sum, ans);
		}
		if (now->right)
		{
			vector<int> next = path;
			next.push_back(now->right->val);
			calc(now->right, next, val + now->right->val, sum, ans);
		}
	}
};
