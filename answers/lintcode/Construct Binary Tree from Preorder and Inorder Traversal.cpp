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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        // in test cases, orders of preorder and inorder are wrong
        return buildTree(0, inorder.size() - 1, 0, preorder.size() - 1, inorder, preorder);
    }
    TreeNode *buildTree(size_t pre_begin, size_t pre_end, size_t in_begin, size_t in_end, const vector<int> &preorder, const vector<int> &inorder) {
    	if (pre_begin > pre_end || pre_end >= preorder.size() || in_begin > in_end || in_end >= inorder.size()) {
    		return NULL;
    	}
    	std::vector<int>::const_iterator it = find(preorder.begin() + pre_begin, preorder.begin() + pre_end, inorder[in_begin]);
    	if (preorder.end() == it) {
    		return NULL;
    	}
    	TreeNode *root = new TreeNode(inorder[in_begin]);
    	cout << "test " << root->val << endl;
    	root->left = buildTree(pre_begin, (it - preorder.begin()) - 1, in_begin + 1, in_begin + (it - preorder.begin()) - pre_begin, preorder, inorder);
    	root->right = buildTree((it - preorder.begin()) + 1, pre_end, in_begin + (it - preorder.begin()) - pre_begin + 1, in_end, preorder, inorder);
    	return root;
    }
};
