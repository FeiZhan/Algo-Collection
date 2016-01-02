//@type Tree
//@result 27 / 27 test cases passed. Status: Accepted Runtime: 40 ms Submitted: 1 minute ago You are here! Your runtime beats 43.06% of cpp submissions.

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (NULL == root || root == p || root == q) {
			return root;
		}
		else {
			TreeNode *left = lowestCommonAncestor(root->left, p, q);
			TreeNode *right = lowestCommonAncestor(root->right, p, q);
			return NULL == left ? right : (NULL == right ? left : root);
		}
    }
};