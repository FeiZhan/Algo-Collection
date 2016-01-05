//@result 114 / 114 test cases passed. Status: Accepted Runtime: 24 ms Submitted: 0 minutes ago You are here! Your runtime beats 12.21% of cpp submissions.

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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<vector<int> > ans;
		if (NULL == root)
		{
			return ans;
		}
		vector<int> path;
		path.push_back(root->val);
		calc(root, path, root->val, sum, ans);
		return ans;
    }
    void calc(const TreeNode *now, const vector<int> &path, int val, int sum, vector<vector<int> > &ans)
    {
		if (NULL == now)
		{
			return;
		}
		if (val == sum && NULL == now->left && NULL == now->right)
		{
			ans.push_back(path);
			return;
		}
		if (now->left)
		{
			vector<int> next = path;
			next.push_back(now->left->val);
			calc(now->left, next, val + now->left->val, sum, ans);
		}
		if (now->right)
		{
			vector<int> next = path;
			next.push_back(now->right->val);
			calc(now->right, next, val + now->right->val, sum, ans);
		}
	}
};
// accepted 2014-03-21
//@result 114 / 114 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago You are here! Your runtime beats 31.51% of cpp submissions.

class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		std::vector< std::vector<int> > ans;
		if (NULL == root)
		{
			return ans;
		}
		std::vector< std::vector<int> > left(pathSum(root->left, sum - root->val));
		std::vector< std::vector<int> > right(pathSum(root->right, sum - root->val));
		ans.reserve(left.size() + right.size()); // preallocate memory
		ans.insert(ans.end(), left.begin(), left.end());
		ans.insert(ans.end(), right.begin(), right.end());
		for (std::vector< std::vector<int> >::iterator it = ans.begin(); it != ans.end(); ++it)
		{
			it->insert(it->begin(), root->val);
		}
		if (NULL == root->left && NULL == root->right && sum == root->val)
		{
			std::vector<int> tmp;
			tmp.push_back(sum);
			ans.push_back(tmp);
		}
		return ans;
	}
};
