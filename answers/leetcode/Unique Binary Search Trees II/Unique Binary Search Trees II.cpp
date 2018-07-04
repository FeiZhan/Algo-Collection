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
	Solution(void) {
		vector<TreeNode *> tree_list;
		//tree_list.push_back(NULL);
		tree_map[0] = tree_list;
		tree_list.clear();
		TreeNode *node = new TreeNode(1);
		tree_list.push_back(node);
		tree_map[1] = tree_list;
	}
	vector<TreeNode *> generateTrees(int n) {
		if (tree_map.end() != tree_map.find(n)) {
			return tree_map[n];
		}
		vector<TreeNode *> tree_list;
		for (int i = 1; i <= n; ++ i) {
			vector<TreeNode *> left_trees = generateTrees(i - 1);
			vector<TreeNode *> right_trees = generateTrees(n - i);
			for (size_t j = 0; j < left_trees.size(); ++ j) {
				for (size_t k = 0; k < right_trees.size(); ++ k) {
					TreeNode *root = new TreeNode(i);
					root->left = copyTree(left_trees[j]);
					root->right = copyTree(right_trees[k], i);
					tree_list.push_back(root);
				}
			}
		}
		tree_map[n] = tree_list;
		return tree_list;
	}
	TreeNode *copyTree(TreeNode *root, int num = 0) {
		if (NULL == root) {
			return NULL;
		}
		TreeNode *new_root = new TreeNode(root->val + num);
		new_root->left = copyTree(root->left, num);
		new_root->right = copyTree(root->right, num);
		return new_root;
	}
	map<int, vector<TreeNode *> > tree_map;
};
