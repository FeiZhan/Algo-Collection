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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        // Write your code here
        vector<vector<int> > path_list;
        vector<int> path;
        binaryTreePaths(root, path, path_list);
        vector<string> str_list;
        for (size_t i = 0; i < path_list.size(); ++ i) {
            string path(to_string(path_list[i][0]));
            for (size_t j = 1; j < path_list[i].size(); ++ j) {
                path += "->" + to_string(path_list[i][j]);
            }
            str_list.push_back(path);
        }
        return str_list;
    }
    void binaryTreePaths(TreeNode *root, vector<int> path, vector<vector<int> > &path_list) {
        if (NULL == root) {
            return;
        }
        path.push_back(root->val);
        if (NULL == root->left && NULL == root->right) {
            path_list.push_back(path);
        }
        else {
            if (root->left) {
                binaryTreePaths(root->left, path, path_list);
            }
            if (root->right) {
                binaryTreePaths(root->right, path, path_list);
            }
        }
    }
};
