//@level Easy
//@type Recursion Binary Tree Binary Tree Traversal
//@result Accepted Total Runtime: 20 ms 100% test cases passed.

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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
		vector<int> traversal;
		stack<TreeNode *> node_stack;
		stack<TreeNode *> root_stack;
		node_stack.push(root);
		while (! node_stack.empty()) {
			TreeNode *current = node_stack.top();
			node_stack.pop();
			if (current) {
				if (! root_stack.empty() && current == root_stack.top()) {
					traversal.push_back(current->val);
					root_stack.pop();
				}
				else {
					node_stack.push(current->right);
					node_stack.push(current);
					node_stack.push(current->left);
					root_stack.push(current);
				}
			}
		}
		return traversal;
    }
};