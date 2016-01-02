//@level Medium 
//@type Divide and Conquer Dynamic Programming Recursion
//@result Accepted Total Runtime: 370 ms 100% test cases passed.

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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
		if (NULL == root) {
			return INT_MIN / 10;
		}
		int left = getPath(root->left);
		int right = getPath(root->right);
		int my_max = max(root->val, max(root->val + left, max(root->val + right, root->val + left + right)));
		return max(my_max, max(maxPathSum(root->left), maxPathSum(root->right)));
    }
	int getPath(TreeNode *root) {
		if (path_map.end() == path_map.find(root)) {
			if (NULL == root) {
				path_map[NULL] = INT_MIN / 10;
			}
			else {
				path_map[root] = max(root->val, max(root->val + getPath(root->left), root->val + getPath(root->right)));
			}
		}
		return path_map[root];
	}
	map<TreeNode *, int> path_map;
};
