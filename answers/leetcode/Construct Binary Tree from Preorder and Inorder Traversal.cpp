// 2015-01-10
// recursion
//@result 202 / 202 test cases passed. Status: Accepted Runtime: 56 ms Submitted: 0 minutes ago You are here! Your runtime beats 14.01% of cpp submissions.

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		return buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
	}
	TreeNode *buildTree(vector<int>::iterator pre_begin, vector<int>::iterator pre_end, vector<int>::iterator in_begin, vector<int>::iterator in_end) {
		if (pre_begin >= pre_end) {
			return NULL;
		}
		TreeNode *root = new TreeNode(*pre_begin);
		vector<int>::iterator in_mid = std::find(in_begin, in_end, root->val);
		root->left = buildTree(pre_begin + 1, pre_begin + 1 + (in_mid - in_begin), in_begin, in_mid);
		root->right = buildTree(pre_begin + 1 + (in_mid - in_begin), pre_end, in_mid + 1, in_end);
		return root;
	}
};
