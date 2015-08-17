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
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == root)
        {
			return 0;
		}
        int sum = 0;
        if (NULL == root->left && NULL == root->right)
        {
			sum += root->val;
		}
        if (NULL != root->left)
        {
			root->left->val += root->val * 10;
			sum += sumNumbers(root->left);
		}
        if (NULL != root->right)
        {
			root->right->val += root->val * 10;
			sum += sumNumbers(root->right);
		}
		return sum;
    }
};
// my idea 2014-04-11
class Solution {
public:
	int sumNumbers(TreeNode *root) {
		std::vector<std::string> list = sumNumList(root);
		int sum(0);
		for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); ++it)
		{
			int temp(0);
			for (size_t i = 0; i < it->length(); ++i)
			{
				temp = temp * 10 + static_cast<int>(it->at(i) - '0');
			}
			sum += temp;
		}
		return sum;
	}
	std::vector<std::string> sumNumList(TreeNode *root)
	{
		std::vector<std::string> ans;
		if (NULL == root)
		{
			return ans;
		}
		std::vector<std::string> left(sumNumList(root->left)), right(sumNumList(root->right));
		ans.reserve(left.size() + right.size());
		ans.insert(ans.end(), left.begin(), left.end());
		ans.insert(ans.end(), right.begin(), right.end());
		if (ans.size() == 0)
		{
			ans.push_back(string(""));
		}
		for (std::vector<std::string>::iterator it = ans.begin(); it != ans.end(); ++it)
		{
			*it = static_cast<char>(root->val + '0') + *it;
		}
		return ans;
	}
};