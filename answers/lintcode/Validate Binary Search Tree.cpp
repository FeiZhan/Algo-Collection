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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
		return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
	bool isValidBST(TreeNode *root, long long min, long long max) {
		return NULL == root || (root->val > min && root->val < max && isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max));
	}
};
