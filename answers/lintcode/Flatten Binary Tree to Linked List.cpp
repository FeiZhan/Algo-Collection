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
    void flatten(TreeNode *root) {
        // write your code here
        if (NULL == root) {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *right = root->right;
        root->right = root->left;
        TreeNode *left = root;
        while (left && left->right) {
            left = left->right;
        }
        left->right = right;
        root->left = NULL;
    }
};
