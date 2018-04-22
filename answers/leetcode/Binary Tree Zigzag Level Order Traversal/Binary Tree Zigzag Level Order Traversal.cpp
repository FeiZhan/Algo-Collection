//@result 33 / 33 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 6.71% of cpp submissions.

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

// 2014-12-19
class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ans;
		if (NULL == root) {
			return ans;
		}
		std::stack<TreeNode *> node_stack;
		std::vector<TreeNode *> node_list;
		node_stack.push(root);
		vector<int> level_ans;
		bool left_flag = true;
		while (!node_stack.empty()) {
			TreeNode *current = node_stack.top();
			node_stack.pop();
			if (current) {
				level_ans.push_back(current->val);
				if (left_flag) {
					node_list.push_back(current->left);
					node_list.push_back(current->right);
				} else {
					node_list.push_back(current->right);
					node_list.push_back(current->left);
				}
			}
			if (node_stack.empty()) {
				if (level_ans.size()) {
					ans.push_back(level_ans);
				}
				level_ans.clear();
				left_flag = ! left_flag;
				for (size_t i = 0; i < node_list.size(); ++ i) {
					node_stack.push(node_list[i]);
				}
				node_list.clear();
			}
		}
		if (level_ans.size()) {
			ans.push_back(level_ans);
		}
		return ans;
	}
};
