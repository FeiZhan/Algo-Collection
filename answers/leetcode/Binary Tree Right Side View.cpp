//@type  Tree Depth-first Search Breadth-first Search
//@result 210 / 210 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 1 minute ago You are here! Your runtime beats 17.52% of cpp submissions.

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_view;
        dfs(0, root, right_view);
        return right_view;
    }
    void dfs(int level, const TreeNode *root, vector<int> &right_view) {
        if (root) {
            if (right_view.size() <= level) {
                right_view.push_back(root->val);
            }
            dfs(level + 1, root->right, right_view);
            dfs(level + 1, root->left, right_view);
        }
    }
};
