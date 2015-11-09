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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if (NULL == root) {
            return root;
        }
        root->left = removeNode(root->left, value);
        root->right = removeNode(root->right, value);
        if (value == root->val) {
            if (NULL == root->left || NULL == root->right) {
                root = root->left ? root->left : root->right;
            }
            else {
                TreeNode *current = root->left;
                while (current && current->right && current->right->right) {
                    current = current->right;
                }
                if (current && current->right) {
                    root->val = current->right->val;
                    current->right = current->right->left;
                }
                else {
                    root->left->right = root->right;
                    root = root->left;
                }
            }
        }
        return root;
    }
};
