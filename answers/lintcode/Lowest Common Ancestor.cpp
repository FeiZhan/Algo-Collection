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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
		if (NULL == root) {
			return NULL;
		}
		else if (root == A || root == B) {
			return root;
		}
		TreeNode *left = lowestCommonAncestor(root->left, A, B);
		TreeNode *right = lowestCommonAncestor(root->right, A, B);
		if (left && right) {
			return root;
		}
		else {
			return left ? left : right;
		}
    }
};
