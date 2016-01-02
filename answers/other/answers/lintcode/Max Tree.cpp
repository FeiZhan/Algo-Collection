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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        stack<TreeNode *> node_stack;
        for (size_t i = 0; i < A.size(); ++ i) {
            TreeNode *root = new TreeNode(A[i]);
            if (node_stack.empty() || node_stack.top()->val >= A[i]) {
                node_stack.push(root);
            }
            else {
                TreeNode *prev = NULL;
                while (! node_stack.empty() && node_stack.top()->val < A[i]) {
                    TreeNode *current = node_stack.top();
                    node_stack.pop();
                    current->right = prev;
                    prev = current;
                }
                root->left = prev;
                node_stack.push(root);
            }
        }
        TreeNode *prev = NULL;
        while (! node_stack.empty()) {
            TreeNode *current = node_stack.top();
            node_stack.pop();
            current->right = prev;
            prev = current;
        }
        return prev;
    }
};
