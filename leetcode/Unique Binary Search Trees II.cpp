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
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return generateTrees(1, n);
    }
	std::vector<TreeNode *> generateTrees(int begin, int end)
	{
		std::vector<TreeNode *> ans;
		if (begin > end)
		{
			ans.push_back(NULL);
			return ans;
		}
		for (int i = begin; i <= end; ++ i)
		{
			std::vector<TreeNode *> left = generateTrees(begin, i - 1);
			std::vector<TreeNode *> right = generateTrees(i + 1, end);
			for (int j = 0; j < left.size(); ++ j)
			{
				for (int k = 0; k < right.size(); ++ k)
				{
					TreeNode *root = new TreeNode(i);
					root->left = left[j];
					root->right = right[k];
					ans.push_back(root);
				}
			}
		}
		return ans;
	}
};
