//@type Tree Binary Search
//@result 18 / 18 test cases passed. Status: Accepted Runtime: 292 ms Submitted: 0 minutes ago

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
    int countNodes(TreeNode* root) {
        if (NULL == root) {
			return 0;
		}
		int left(getLeft(root->left));
		if (getRight(root->right) == left) {
			return (2 << left) - 1;
		}
		else {
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
    }
	int getLeft(TreeNode *root) {
		return NULL == root ? 0 : getLeft(root->left) + 1;
	}
	int getRight(TreeNode *root) {
		return NULL == root ? 0 : getRight(root->right) + 1;
	}
};

int main() {
	// your code goes here
	return 0;
}