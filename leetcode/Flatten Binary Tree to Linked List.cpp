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
#include <queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void printTree(const TreeNode *root)
{
	queue<const TreeNode *> st;
	st.push(root);
	while (! st.empty())
	{
		if (st.front())
		{
			cout << st.front()->val << ", ";
		}
		if (st.front()->left)
		{
			st.push(st.front()->left);
		} else
		{
			cout << st.front()->val << "left#, ";
		}
		if (st.front()->right)
		{
			st.push(st.front()->right);
		} else
		{
			cout << st.front()->val << "right#, ";
		}
		st.pop();
	}
	cout << endl;
}
class Solution {
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        flat(root);
	}
    TreeNode *flat(TreeNode *root) {
        if (NULL == root)
        {
			return NULL;
		}
		TreeNode *end = root;
		if (NULL != root->left)
		{
			TreeNode *tail = flat(root->left);
			if (NULL != root->right)
			{
				end = flat(root->right);
				tail->right = root->right;
			} else
			{
				end = tail;
			}
			root->right = root->left;
			// delete the original left branch
			root->left = NULL;
		}
		// right branch should still be considered
		if (NULL != root->right)
		{
			end = flat(root->right);
		}
//cout << "testing " << root->val << ": ";
//printTree(root);
		return end;
    }
};
int main(int argc, char *argv[])
{
	TreeNode *root;
	Solution s;
	// {1,#,2}
	// {1,#,2,3}
	root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	s.flatten(root);
	printTree(root);
	return 0;
}

// 2015-1-1
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
	void flatten(TreeNode *root) {
		flattenRec(root);
	}
	TreeNode *flattenRec(TreeNode *root) {
		if (NULL == root) {
			return NULL;
		}
		TreeNode *left_end = flattenRec(root->left);
		if (left_end) {
			left_end->right = root->right;
			root->right = root->left;
			root->left = NULL;
		} else {
			left_end = root;
		}
		TreeNode *right_end = flattenRec(left_end->right);
		if (right_end) {
			return right_end;
		} else {
			return left_end;
		}
	}
};
