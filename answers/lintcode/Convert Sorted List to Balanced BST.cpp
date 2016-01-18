//@result Accepted Total Runtime: 78 ms 100% test cases passed.

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        int count = 0;
        ListNode *current = head;
        while (current) {
            ++ count;
            current = current->next;
        }
        return sortedListToBST(head, count);
    }
    // pass head as reference
    TreeNode *sortedListToBST(ListNode *&head, int count) {
        TreeNode *root = NULL;
        if (head) {
            if (1 == count) {
                root = new TreeNode(head->val);
                head = head->next;
            }
            else if (count > 1) {
                root = new TreeNode(INT_MAX);
                root->left = sortedListToBST(head, count / 2);
                root->val = head->val;
                head = head->next;
                root->right = sortedListToBST(head, (count - 1) / 2);
            }
        }
        return root;
    }
};
