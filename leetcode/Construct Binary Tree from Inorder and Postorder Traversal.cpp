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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    TreeNode *build(const std::vector<int> &inorder, const int in_begin, const int in_end, const std::vector<int> &postorder, const int post_begin, const int post_end)
    {
		if (post_begin > post_end)
		{
			return NULL;
		}
		TreeNode *now(new TreeNode(postorder[post_end]));
		const size_t parent( std::distance( inorder.begin(), std::find(inorder.begin() + in_begin, inorder.begin() + in_end + 1, now->val) ) );
		const size_t left_size(parent - in_begin);
		now->left = build(inorder, in_begin, parent - 1, postorder, post_begin, post_begin + left_size - 1);
		now->right = build(inorder, parent + 1, in_end, postorder, post_begin + left_size, post_end - 1);
		return now;
	}
};

// 2015-1-1
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
	}
	TreeNode *buildTree(vector<int>::iterator in_begin, vector<int>::iterator in_end, vector<int>::iterator post_begin, vector<int>::iterator post_end) {
		if (in_begin == in_end || post_begin == post_end) {
			return NULL;
		}
		TreeNode *root = new TreeNode(*(post_end - 1));
		vector<int>::iterator in_root = std::find(in_begin, in_end, root->val);
		root->left = buildTree(in_begin, in_root, post_begin, post_begin + (in_root - in_begin));
		root->right = buildTree(in_root + 1, in_end,  post_begin + (in_root - in_begin), post_end - 1);
		return root;
	}
};
