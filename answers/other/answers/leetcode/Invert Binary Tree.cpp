//@type Tree
//@result 68 / 68 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 1 minute ago You are here! Your runtime beats 12.65% of cpp submissions.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (NULL != root) {
			TreeNode *temp = invertTree(root->left);
			root->left = invertTree(root->right);
			root->right = temp;
		}
		return root;
    }
};