/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
#include <climits>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	Solution() : max(INT_MIN)
	{}
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        max = INT_MIN;
        maxPath(root);
        return max;
	}
    int maxPath(TreeNode *root) {
        if (NULL == root)
        {
			return INT_MIN;
		}
//cout << "starting " << root->val << endl;
		if (NULL == root->left && NULL == root->right)
		{
			if (root->val > max)
			{
				max = root->val;
			}
//cout << "a " << max << " " << root->val << endl;
			return root->val;
		} else if (NULL == root->right)
		{
			int left = maxPath(root->left);
			if (left <= 0)
			{
				left = root->val;
			} else
			{
				left += root->val;
			}
			if (left > max)
			{
				max = left;
			}
//cout << "b " << max << " " << left << endl;
			return left;
		} else if (NULL == root->left)
		{
			int right = maxPath(root->right);
			if (right <= 0)
			{
				right = root->val;
			} else
			{
				right += root->val;
			}
			if (right > max)
			{
				max = right;
			}
//cout << "c " << max << " " << right << endl;
			return right;
		} else
		{
			int bigger, ret;
			int left = maxPath(root->left);
			if (left <= 0)
			{
				ret = bigger = root->val;
			} else
			{
				ret = bigger = left + root->val;
			}
			if (bigger > max)
			{
				max = bigger;
			}
			int right = maxPath(root->right);
			if (right > 0)
			{
				bigger += right;
			}
			if (right + root->val > ret)
			{
				ret = right + root->val;
			}
			if (bigger > max)
			{
				max = bigger;
			}
//cout << "d " << max << " " << bigger << " " << ret << " " << left << " " << right << endl;
			return ret;
		}
    }
    int max;
};
int main(int argc, char *argv[])
{
	Solution s;
	// {-3}
	TreeNode *root = new TreeNode(-3);
	cout << s.maxPathSum(root) << endl;
	// {2,-1}
	root = new TreeNode(2);
	root->left = new TreeNode(-1);
	cout << s.maxPathSum(root) << endl;
	// {-2,1}
	root = new TreeNode(-2);
	root->left = new TreeNode(1);
	cout << s.maxPathSum(root) << endl;
	// {1,-2,-3,1,3,-2,#,-1}
	root = new TreeNode(1);
	root->left = new TreeNode(-2);
	root->right = new TreeNode(-3);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right->left = new TreeNode(-2);
	root->left->left->left = new TreeNode(-1);
	cout << s.maxPathSum(root) << endl;
	return 0;
}


// 2014-12-14
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
	Solution(void) {
		// cannot be set to -INT_MAX because of addition with negative value
		max_path_sum = -10000;
	}
	int maxPathSum(TreeNode *root) {
		getNodeSum(root);
		return max_path_sum;
	}
	int getNodeSum(TreeNode *root) {
		if (NULL == root) {
			return -10000;
		}
		int node_sum = root->val;
		if (root->val > max_path_sum) {
			max_path_sum = root->val;
		}
		int left_sum = getNodeSum(root->left);
		if (root->val + left_sum > max_path_sum) {
			max_path_sum = root->val + left_sum;
		}
		if (root->val + left_sum > node_sum) {
			node_sum = root->val + left_sum;
		}
		int right_sum = getNodeSum(root->right);
		if (root->val + right_sum > max_path_sum) {
			max_path_sum = root->val + right_sum;
		}
		if (root->val + right_sum > node_sum) {
			node_sum = root->val + right_sum;
		}
		if (root->val + left_sum + right_sum > max_path_sum) {
			max_path_sum = root->val + left_sum + right_sum;
		}
		return node_sum;
	}
	int max_path_sum;
};
