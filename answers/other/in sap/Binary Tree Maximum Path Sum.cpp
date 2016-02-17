//@result 92 / 92 test cases passed. Status: Accepted Runtime: 32 ms Submitted: 0 minutes ago You are here! Your runtime beats 26.31% of cpp submissions.

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
    int maxPathSum(TreeNode* root) {
    	int max_path = INT_MIN / 10;
    	maxPathSum(root, max_path);
    	return max_path;
    }
    int maxPathSum(TreeNode *root, int &max_path) {
        // cannot set to  INT_MIN, because adding to other number
    	int path = INT_MIN / 10;
    	if (root) {
    		path = max(path, root->val);
    		max_path = max(max_path, root->val);
    		int left = maxPathSum(root->left, max_path);
    		path = max(path, root->val + left);
    		max_path = max(max_path, root->val + left);
    		int right = maxPathSum(root->right, max_path);
    		path = max(path, root->val + right);
    		max_path = max(max_path, root->val + right);
    		max_path = max(max_path, left + root->val + right);
    	}
    	return path;
    }
};