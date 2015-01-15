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
	void recoverTree(TreeNode *root) {
		inorder(root);
		sort(val_list.begin(), val_list.end());
		for (size_t i = 0; i < node_list.size() && i < val_list.size(); ++i) {
			node_list[i]->val = val_list[i];
		}
	}
	void inorder(TreeNode *root) {
		if (NULL == root) {
			return;
		}
		inorder(root->left);
		node_list.push_back(root);
		val_list.push_back(root->val);
		inorder(root->right);
	}
	vector<TreeNode *> node_list;
	vector<int> val_list;
};

// http://fisherlei.blogspot.ca/2012/12/leetcode-recover-binary-search-tree.html

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
	void recoverTree(TreeNode *root) {
		TreeNode *f1 = NULL, *f2 = NULL;
		TreeNode *current = NULL, *pre = NULL, *parent = NULL;
		if (NULL == root) {
			return;
		}
		bool found_flag = false;
		current = root;
		while (current) {
			if (NULL == current->left) {
				if (parent && parent->val > current->val) {
					if (!found_flag) {
						f1 = parent;
						found_flag = true;
					}
					f2 = current;
				}
				parent = current;
				current = current->right;
			}
			else {
				pre = current->left;
				while (pre->right && pre->right != current) {
					pre = pre->right;
				}
				if (NULL == pre->right) {
					pre->right = current;
					current = current->left;
				}
				else {
					pre->right = NULL;
					if (parent->val > current->val) {
						if (!found_flag) {
							f1 = parent;
							found_flag = true;
						}
						f2 = current;
					}
					parent = current;
					current = current->right;
				}
			}
		}
		if (f1 && f2) {
			int temp = f1->val;
			f1->val = f2->val;
			f2->val = temp;
		}
	}
};