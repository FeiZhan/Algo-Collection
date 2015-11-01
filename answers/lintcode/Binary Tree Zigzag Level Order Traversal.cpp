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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        // write your code here
		vector<vector<int> > traversal;
		zigzagLevelOrder(root, 0, traversal);
		for (size_t i = 1; i < traversal.size(); i += 2) {
			reverse(traversal[i].begin(), traversal[i].end());
		}
		return traversal;
    }
	void zigzagLevelOrder(TreeNode *root, int level, vector<vector<int> > &traversal) {
		if (NULL == root) {
			return;
		}
		if (traversal.size() <= level) {
			traversal.resize(level + 1);
		}
		traversal[level].push_back(root->val);
		zigzagLevelOrder(root->left, level + 1, traversal);
		zigzagLevelOrder(root->right, level + 1, traversal);
	}
};
