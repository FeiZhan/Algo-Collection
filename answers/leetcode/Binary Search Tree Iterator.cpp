/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) : root(root) {
		TreeNode *current = root;
		while (current) {
			node_list.push(current);
			current = current->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return ! node_list.empty();
    }

    /** @return the next smallest number */
    int next() {
		if (hasNext()) {
			TreeNode *current = node_list.top();
			node_list.pop();
			int next_val = INT_MAX;
			if (current) {
				next_val = current->val;
				current = current->right;
				while (current) {
					node_list.push(current);
					current = current->left;
				}
			}
			return next_val;
		}
		return INT_MAX;
    }
    TreeNode *root;
    std::stack<TreeNode *> node_list;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
