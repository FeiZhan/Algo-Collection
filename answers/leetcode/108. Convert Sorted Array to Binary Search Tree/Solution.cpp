// 2014-04-17
//@result 32 / 32 test cases passed. Status: Accepted Runtime: 16 ms Submitted: 0 minutes ago You are here! Your runtime beats 68.53% of cpp submissions.

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
