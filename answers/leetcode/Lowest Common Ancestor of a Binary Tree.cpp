//@type Tree
//@time complexity O(n)
//@space complexity O(log(n))
//@result 31 / 31 test cases passed. Status: Accepted Runtime: 24 ms Submitted: 0 minutes ago You are here! Your runtime beats 27.36% of cpp submissions.

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
        // find at least one
        if (NULL == root || p == root || q == root) {
			return root;
		}
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // find at least one in both branch
		if (left && right) {
			return root;
		}
        else if (left) {
            return left;
        }
        else if (right) {
            return right;
        }
        else {
            return NULL;
        }
    }
};
