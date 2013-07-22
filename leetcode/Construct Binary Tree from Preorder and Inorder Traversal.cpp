//undone

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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *ans = NULL;
        if (preorder.size() == 0 || inorder.size() == 0)
        {
			return ans;
		}
		ans = new TreeNode(0);
        if (preorder.size() == 1 && inorder.size() == 1 && preorder[0] == inorder[0])
        {
			ans->val = preorder[0];
		} else
        {
			ans->val = inorder[0];
			vector<int> pre, in;
			int parent = 
			pre.push_back(preorder[0]);
			in.push_back(inorder[1]);
			ans->left = buildTree(pre, in);
		} else if 
		return ans;
    }
};
