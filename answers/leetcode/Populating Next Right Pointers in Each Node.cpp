//@result 14 / 14 test cases passed. Status: Accepted Runtime: 24 ms Submitted: 0 minutes ago You are here! Your runtime beats 42.22% of cpp submissions.

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
