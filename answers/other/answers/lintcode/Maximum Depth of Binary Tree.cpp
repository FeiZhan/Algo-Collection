/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        // write your code here
		int max_depth = 0;
		maxDepth(root, 1, max_depth);
		return max_depth;
    }
	void maxDepth(TreeNode *root, int current, int &max_depth) {
		if (NULL == root) {
			return;
		}
		max_depth = max(max_depth, current);
		maxDepth(root->left, current + 1, max_depth);
		maxDepth(root->right, current + 1, max_depth);
	}
};
