//@algorithm binary search tree
//@time complexity O(k)
//@space complexity O(height)
//@result 91 / 91 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago You are here! Your runtime beats 46.63% of cpp submissions.

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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return kthSmallest(root, count, k);
    }
    int kthSmallest(TreeNode *root, int &count, int k) {
        if (NULL == root) {
            return 0;
        }
        int left = kthSmallest(root->left, count, k);
        if (count >= k) {
            return left;
        }
        ++ count;
        if (count >= k) {
            return root->val;
        }
        int right = kthSmallest(root->right, count, k);
        return right;
    }
};
