//@result 225 / 225 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 14.38% of cpp submissions.

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
	void flatten(TreeNode *root) {
		flattenRec(root);
	}
	TreeNode *flattenRec(TreeNode *root) {
		if (NULL == root) {
			return NULL;
		}
		TreeNode *left_end = flattenRec(root->left);
		if (left_end) {
			left_end->right = root->right;
			root->right = root->left;
			root->left = NULL;
		} else {
			left_end = root;
		}
		TreeNode *right_end = flattenRec(left_end->right);
		if (right_end) {
			return right_end;
		} else {
			return left_end;
		}
	}
};
