//@level Easy
//@type LintCode Copyright Binary Search Tree
//@result Accepted Total Runtime: 47 ms 100% test cases passed.

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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
		if (NULL == root) {
			return node;
		}
		else if (node) {
			if (node->val < root->val) {
				root->left = insertNode(root->left, node);
			}
			else if (node->val > root->val) {
				root->right = insertNode(root->right, node);
			}
		}
		return root;
    }
};