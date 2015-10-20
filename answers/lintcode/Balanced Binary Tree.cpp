//@level Medium 
//@type Binary Search Divide and Conquer Recursion
//@result Accepted Total Runtime: 14 ms 100% test cases passed.

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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
		return NULL == root || (abs(getHeight(root->left) - getHeight(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right));
    }
	int getHeight(TreeNode *root) {
		if (height_map.end() == height_map.find(root)) {
			if (NULL == root) {
				height_map[root] = 0;
			}
			else {
				height_map[root] = max(getHeight(root->left), getHeight(root->right)) + 1;
			}
		}
		return height_map[root];
	}
	map<TreeNode *, int> height_map;
};
