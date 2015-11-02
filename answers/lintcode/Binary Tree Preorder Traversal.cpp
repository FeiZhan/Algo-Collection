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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> traversal;
        preorderTraversal(root, traversal);
        return traversal;
    }
    void preorderTraversal(TreeNode *root, std::vector<int> &traversal) {
    	if (NULL == root) {
    		return;
    	}
    	traversal.push_back(root->val);
    	preorderTraversal(root->left, traversal);
    	preorderTraversal(root->right, traversal);
    }
};

