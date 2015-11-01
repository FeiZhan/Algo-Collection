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
    int minDepth(TreeNode *root) {
        // write your code here
		int min_depth = INT_MAX;
		minDepth(root, 0, min_depth);
		return root ? min_depth : 0;
    }
	void minDepth(TreeNode *root, int current, int &min_depth) {
		if (current >= min_depth || NULL == root) {
			return;
		}
		if (NULL == root->left && NULL == root->right) {
			min_depth = min(min_depth, current + 1);
		}
		minDepth(root->left, current + 1, min_depth);
		minDepth(root->right, current + 1, min_depth);
	}
};
