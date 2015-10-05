//@type  Tree Depth-first Search Breadth-first Search
//@result 210 / 210 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 1 minute ago

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
		if (NULL == root) {
			return ans;
		}
		vector<int> left = rightSideView(root->left);
		vector<int> right = rightSideView(root->right);
		ans.push_back(root->val);
		for (size_t i = 0; i < left.size() || i < right.size(); ++ i) {
			if (i < right.size()) {
				ans.push_back(right[i]);
			}
			else {
				ans.push_back(left[i]);
			}
		}
		return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}