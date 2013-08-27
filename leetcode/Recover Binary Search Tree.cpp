// copied from leetcode, undone

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
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		TreeNode *f1 = NULL, *f2 = NULL, *pre = NULL, *par = NULL;
		bool found = false;
		while (root)
		{
			if (NULL == h->left)
			{
				if (par && par->val > h->val)
				{
					if (! found)
					{
						f1 = par;
						found = true;
					}
					f2 = root;
				}
				par = root;
				root = root->right;
				continue;
			}
		}
    }
};
