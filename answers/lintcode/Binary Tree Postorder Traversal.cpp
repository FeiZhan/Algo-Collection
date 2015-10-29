//@result Accepted Total Runtime: 11 ms 100% test cases passed.

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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
		vector<int> answer;
		postorderTraversal(root, answer);
		return answer;
    }
	void postorderTraversal(TreeNode *root, vector<int> &answer) {
		if (NULL == root) {
			return;
		}
		postorderTraversal(root->left, answer);
		postorderTraversal(root->right, answer);
		answer.push_back(root->val);
	}
};
