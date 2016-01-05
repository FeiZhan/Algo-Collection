// 2015-01-12
// bfs
//@result 61 / 61 test cases passed. Status: Accepted Runtime: 36 ms Submitted: 0 minutes ago You are here! Your runtime beats 73.87% of cpp submissions.

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
		TreeLinkNode *head = root;
		while (head) {
			TreeLinkNode *parent = head;
			TreeLinkNode *current = NULL;
			while (parent) {
				if (current) {
					current->next = parent->left;
				}
				else {
					current = parent->left;
				}
				if (current && current->next) {
					current = current->next;
				}
				if (current) {
					current->next = parent->right;
				}
				else {
					current = parent->right;
				}
				if (current && current->next) {
					current = current->next;
				}
				parent = parent->next;
				if (NULL == head->left && NULL == head->right && parent) {
					head = parent;
				}
			}
			head = head->left ? head->left : head->right;
		}
	}
};
