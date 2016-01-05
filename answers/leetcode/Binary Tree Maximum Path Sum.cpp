//@result 92 / 92 test cases passed. Status: Accepted Runtime: 32 ms Submitted: 17 minutes ago You are here! Your runtime beats 26.31% of cpp submissions.

// 2014-12-14
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
	Solution(void) {
		// cannot be set to -INT_MAX because of addition with negative value
		max_path_sum = -10000;
	}
	int maxPathSum(TreeNode *root) {
		getNodeSum(root);
		return max_path_sum;
	}
	int getNodeSum(TreeNode *root) {
		if (NULL == root) {
			return -10000;
		}
		int node_sum = root->val;
		if (root->val > max_path_sum) {
			max_path_sum = root->val;
		}
		int left_sum = getNodeSum(root->left);
		if (root->val + left_sum > max_path_sum) {
			max_path_sum = root->val + left_sum;
		}
		if (root->val + left_sum > node_sum) {
			node_sum = root->val + left_sum;
		}
		int right_sum = getNodeSum(root->right);
		if (root->val + right_sum > max_path_sum) {
			max_path_sum = root->val + right_sum;
		}
		if (root->val + right_sum > node_sum) {
			node_sum = root->val + right_sum;
		}
		if (root->val + left_sum + right_sum > max_path_sum) {
			max_path_sum = root->val + left_sum + right_sum;
		}
		return node_sum;
	}
	int max_path_sum;
};
