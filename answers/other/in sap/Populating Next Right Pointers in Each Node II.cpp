//@result 61 / 61 test cases passed. Status: Accepted Runtime: 40 ms Submitted: 0 minutes ago You are here! Your runtime beats 19.13% of cpp submissions.

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
        TreeLinkNode *leftmost = root;
        while (leftmost) {
        	TreeLinkNode *parent = leftmost;
	        while (parent) {
	        	TreeLinkNode *begin = NULL;
	        	if (parent->left) {
	        		if (parent->right) {
	        			parent->left->next = parent->right;
	        		}
	        		else {
	        			begin = parent->left;
	        		}
	        	}
        		if (parent->right) {
        			begin = parent->right;
        		}
        		if (begin) {
		        	TreeLinkNode *temp = parent->next;
		        	while (temp) {
		        		if (temp->left) {
		        			begin->next = temp->left;
		        			break;
		        		}
		        		else if (temp->right) {
		        			begin->next = temp->right;
		        			break;
		        		}
		        		temp = temp->next;
		        	}
        		}
	        	parent = parent->next;
	        }
	        while (leftmost) {
	        	if (leftmost->left) {
	        		leftmost = leftmost->left;
	        		break;
	        	}
	        	else if (leftmost->right) {
	        		leftmost = leftmost->right;
	        		break;
	        	}
	        	leftmost = leftmost->next;
	        }
	    }
    }
};