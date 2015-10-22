//@level Hard 
//@type LintCode Copyright Binary Search Tree Binary Tree Non Recursion
//@result Accepted Total Runtime: 26 ms 100% test cases passed.

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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
		TreeNode *current = root;
		while (current) {
			parent_stack.push(current);
			current = current->left;
		}
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
		return ! parent_stack.empty();
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
		if (! hasNext()) {
			return NULL;
		}
		else {
			TreeNode *current = parent_stack.top();
			parent_stack.pop();
			if (current && current->right) {
				TreeNode *temp = current->right;
				while (temp) {
					parent_stack.push(temp);
					temp = temp->left;
				}
			}
			return current;
		}
    }
	stack<TreeNode *> parent_stack;
};
