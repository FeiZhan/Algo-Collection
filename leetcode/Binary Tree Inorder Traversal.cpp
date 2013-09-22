// a stack directly

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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<int> ans;
		if (NULL == root)
		{
			return ans;
		}
		std::stack<TreeNode *> node_stack;
		node_stack.push(root);
		while (! node_stack.empty())
		{
			TreeNode *now = node_stack.top();
			node_stack.pop();
			if (NULL == now)
			{
				continue;
			}
			if (node_stack.empty() || now->right != node_stack.top())
			{
				node_stack.push(now->right);
				node_stack.push(now);
				node_stack.push(now->left);
			} else
			{
				ans.push_back(now->val);
			}
		}
		return ans;
    }
};
