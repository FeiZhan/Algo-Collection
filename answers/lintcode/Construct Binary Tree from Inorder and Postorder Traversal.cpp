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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
		return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
    TreeNode *buildTree(const vector<int> &inorder, const vector<int> &postorder, size_t inbegin, size_t inend, size_t postbegin, size_t postend) {
		if (postbegin > postend || postend >= postorder.size()) {
			return NULL;
		}
		vector<int>::const_iterator it = find(inorder.begin(), inorder.end(), postorder[postend]);
		if (inorder.end() == it) {
			return NULL;
		}
		size_t root = distance(inorder.begin(), it);
		TreeNode *current = new TreeNode(postorder[postend]);
		current->left = buildTree(inorder, postorder, inbegin, root - 1, postbegin, postbegin + root - 1 - inbegin);
		current->right = buildTree(inorder, postorder, root + 1, inend, postbegin + root - inbegin, postend - 1);
		return current;
	}
};
