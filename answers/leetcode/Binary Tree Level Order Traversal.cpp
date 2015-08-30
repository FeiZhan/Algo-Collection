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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ans.clear();
		levelOrderRec(root, 0);
		return ans;
    }
    void levelOrderRec(const TreeNode *root, int level)
    {
		if (root)
		{
			addToAns(root->val, level);
		} else
		{
			return;
		}
		if (root->left)
		{
			levelOrderRec(root->left, level + 1);
		}
		if (root->right)
		{
			levelOrderRec(root->right, level + 1);
		}
	}
	void addToAns(int value, int level)
	{
		while (ans.size() <= level)
		{
			vector<int> tmp;
			ans.push_back(tmp);
		}
		ans[level].push_back(value);
	}
    vector<vector<int> > ans;
};

// 2015-1-1
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
