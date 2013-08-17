//WA
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
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void outputTree(const TreeNode *root)
{
	if (NULL == root)
	{
		cout << "NULL";
		return;
	}
	cout << "{ " << root->val << " : ";
	outputTree(root->left);
	cout << " , ";
	outputTree(root->right);
	cout << " }";
}
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> mistake;
		check(root, NULL, NULL, NULL, mistake);
cout << "mistakes " << mistake.size() << " : ";
		for (size_t i = 0; i < mistake.size(); ++ i)
		{
			cout << mistake[i]->val << " ";
		}
cout << endl;
		if (mistake.size() < 2)
		{
			if (root && root->left)
			{
				mistake.push_back(root);
				mistake.push_back(root->left);
			}
			else if (root && root->right)
			{
				mistake.push_back(root);
				mistake.push_back(root->right);
			}
		}
		if (mistake.size() >= 2)
		{
			int tmp = mistake[0]->val;
			mistake[0]->val = mistake[1]->val;
			mistake[1]->val = tmp;
		}
    }
    void check(TreeNode *root, const TreeNode *parent, const TreeNode *grandma, const TreeNode *grandfa, vector<TreeNode *> &mistake)
    {
		if (NULL == root)
		{
			return;
		}
cout << "test " << root->val << " : " << (NULL != parent);
if (NULL != parent)
{
	cout << " " << (parent->left == root) << " " << (root->val >= parent->val);
}
cout << endl;
		if ( (parent && parent->left == root && root->val >= parent->val) ||
			(parent && parent->right == root && root->val <= parent->val) ||
			(grandfa && root->val >= grandfa->val) ||
			(grandma && root->val <= grandma->val) )
		{
			mistake.push_back(root);
		}
		if (NULL == parent || parent->left == root)
		{
			check(root->left, root, NULL, parent, mistake);
			check(root->right, root, NULL, parent, mistake);
		}
		else if (NULL == parent || parent->right == root)
		{
			check(root->left, root, parent, NULL, mistake);
			check(root->right, root, parent, NULL, mistake);
		}
	}
};
int main()
{
	Solution s;
	//{2,3,1}
	//{3,#,2,#,1}
	TreeNode *root = new TreeNode(3);
	root->right = new TreeNode(2);
	root->right->right = new TreeNode(1);
	s.recoverTree(root);
	outputTree(root);
	return 0;
}
