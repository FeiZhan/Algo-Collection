//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// Recursive
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		std::vector<int> ans;
		if (NULL == root)
		{
			return ans;
		}
		std::vector<int> left(preorderTraversal(root->left)), right(preorderTraversal(root->right));
		ans.reserve(1 + left.size() + right.size());
		ans.push_back(root->val);
		ans.insert(ans.end(), left.begin(), left.end());
		ans.insert(ans.end(), right.begin(), right.end());
		return ans;
	}
};
// iteratively
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		std::vector<int> ans;
		if (NULL == root)
		{
			return ans;
		}
		std::stack<TreeNode *> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode *top = s.top();
			s.pop();
			if (NULL == top)
			{
				continue;
			}
			ans.push_back(top->val);
			// reverse order
			s.push(top->right);
			s.push(top->left);
		}
		return ans;
	}
};