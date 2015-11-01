//@level Medium 
//@type Queue Binary Tree Binary Tree Traversal Breadth First Search
//@result Accepted Total Runtime: 13 ms 100% test cases passed.

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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
		answer.clear();
		levelOrderBottom(root, 0);
		return answer;
    }
    void levelOrderBottom(TreeNode *root, int level) {
		if (NULL == root) {
			return;
		}
		while (level >= answer.size()) {
			answer.insert(answer.begin(), vector<int> ());
		}
		answer[answer.size() - 1 - level].push_back(root->val);
		levelOrderBottom(root->left, level + 1);
		levelOrderBottom(root->right, level + 1);
	}
	vector<vector<int> > answer;
};

