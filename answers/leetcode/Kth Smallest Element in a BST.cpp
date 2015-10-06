//@type  Tree Binary Search
//@result 91 / 91 test cases passed. Status: Accepted Runtime: 40 ms Submitted: 1 minute ago

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
    int kthSmallest(TreeNode* root, int k) {
		return getValues(root)[k - 1];
    }
	vector<int> getValues(TreeNode *root) {
		vector<int> node_list;
		if (NULL == root) {
			return node_list;
		}
		node_list = getValues(root->left);
		node_list.push_back(root->val);
		vector<int> node_list1 = getValues(root->right);
		node_list.insert(node_list.end(), node_list1.begin(), node_list1.end());
		return node_list;
	}
};

int main() {
	// your code goes here
	return 0;
}