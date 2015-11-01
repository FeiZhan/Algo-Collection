//@level Medium 
//@type Queue Binary Tree Binary Tree Traversal Breadth First Search
//@result Accepted Total Runtime: 17 ms 100% test cases passed.

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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // write your code here
		answer.clear();
		levelOrder(root, 0);
		return answer;
    }
    void levelOrder(TreeNode *root, int level) {
		if (NULL == root) {
			return;
		}
		if (level >= answer.size()) {
			answer.resize(level + 1, vector<int> ());
		}
		answer[level].push_back(root->val);
		levelOrder(root->left, level + 1);
		levelOrder(root->right, level + 1);
	}
	vector<vector<int> > answer;
};

