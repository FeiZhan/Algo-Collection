// copied from leetcode

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (0 == num.size())
		{
			return NULL;
		}
		if (1 == num.size())
		{
			return new TreeNode(num[0]);
		}
		std::vector<int> left(num.begin(), num.begin() + num.size() / 2);
		std::vector<int> right(num.begin() + num.size() / 2 + 1, num.end());
		TreeNode *root = new TreeNode(num[num.size() / 2]);
		root->left = sortedArrayToBST(left);
		root->right = sortedArrayToBST(right);
		return root;
    }
};
// 2014-04-17
class Solution {
public:
	TreeNode *sortedArrayToBST(vector<int> &num) {
		return sortedArrayToBST(num, 0, num.size());
	}
	TreeNode *sortedArrayToBST(const vector<int> &num, int left, int right)
	{
		if (left >= right)
		{
			return NULL;
		}
		int mid = (left + right) / 2;
		TreeNode *root(new TreeNode(num[mid]));
		root->left = sortedArrayToBST(num, left, mid);
		root->right = sortedArrayToBST(num, mid + 1, right);
		return root;
	}
};