//@type Tree
//@result 31 / 31 test cases passed. Status: Accepted Runtime: 44 ms Submitted: 0 minutes ago

#include <iostream>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (NULL == root) {
			return NULL;
		}
		if (p == root && q == root) {
			return root;
		}
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		if (left) {
			return left;
		}
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (right) {
			return right;
		}
		if (find(root, p) && find(root, q)) {
			return root;
		}
		else {
			return NULL;
		}
    }
	bool find(TreeNode *root, TreeNode *target) {
		return root && (root == target || find(root->left, target) || find(root->right, target));
	}
};

int main() {
	// your code goes here
	return 0;
}