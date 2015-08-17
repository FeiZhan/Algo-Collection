// copied from leetcode, redo at 2013-09-22

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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		while (root)
		{
			TreeLinkNode *next = NULL; // begin or the next level
			TreeLinkNode *prev = NULL;
			while (root)
			{
				if (! next)
				{
					next = root->left ? root->left : root->right;
				}
				if (root->left)
				{
					if (prev)
					{
						prev->next = root->left;
					}
					prev = root->left;
				}
				if (root->right)
				{
					if (prev)
					{
						prev->next = root->right;
					}
					prev = root->right;
				}
				root = root->next;
			}
			root = next;
		}
    }
};

// 2015-01-12
// bfs
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