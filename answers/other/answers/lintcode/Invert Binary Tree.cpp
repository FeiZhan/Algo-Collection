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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
		if (NULL == root) {
			return;
		}
		invertBinaryTree(root->left);
		invertBinaryTree(root->right);
		TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
    }
};
