//@type  Tree Depth-first Search
//@result 209 / 209 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 11.54% of cpp submissions.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        return dfs(root, vector<int> ());
    }
	vector<string> dfs(TreeNode *root, vector<int> path) {
		vector<string> paths;
		if (NULL == root) {
		}
		else if (NULL == root->left && NULL == root->right) {
			string path_str;
			for (size_t i = 0; i < path.size(); ++ i) {
				path_str += string(to_string(path[i])) + "->";
			}
			path_str += string(to_string(root->val));
			paths.push_back(path_str);
		}
		else {
			path.push_back(root->val);
			if (NULL != root->left) {
				vector<string> left(dfs(root->left, path));
				paths.insert(paths.end(), left.begin(), left.end());
			}
			if (NULL != root->right) {
				vector<string> right(dfs(root->right, path));
				paths.insert(paths.end(), right.begin(), right.end());
			}
		}
		return paths;
	}
};