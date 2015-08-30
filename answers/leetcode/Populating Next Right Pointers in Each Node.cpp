// recursive version, not good

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (NULL == root) {
			return;
		}
		TreeLinkNode *current_parent = root;
		TreeLinkNode *current = NULL;
		while (current_parent) {
			if (current_parent->left) {
				current = current_parent->left;
				current->next = current_parent->right;
			}
			if (current_parent->right) {
				current = current_parent->right;
			}
			if (current_parent->next) {
				if (current_parent->next->left) {
					current->next = current_parent->next->left;
					current = current_parent->next->left;
				}
				else if (current_parent->next->right) {
					current->next = current_parent->next->right;
					current = current_parent->next->right;
				}
			}
			current_parent = current_parent->next;
		}
		connect(root->left);
		connect(root->right);
    }
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
		TreeLinkNode *level = root;
		while (level) {
			TreeLinkNode *current_parent = level;
			TreeLinkNode *current = NULL;
			while (current_parent) {
				if (current_parent->left) {
					current = current_parent->left;
					current->next = current_parent->right;
				}
				if (current_parent->right) {
					current = current_parent->right;
				}
				// if no children
				if (current && current_parent->next) {
					current->next = current_parent->next->left ? current_parent->next->left : current_parent->next->right;
				}
				current_parent = current_parent->next;
			}
			level = level->left ? level->left : level->right;
		}
    }
};
