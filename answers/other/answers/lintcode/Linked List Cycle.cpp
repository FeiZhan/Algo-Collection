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
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        // write your code here
        if (NULL == head) {
            return false;
        }
        ListNode *left = head;
        ListNode *right = head->next;
        while (left && right && right->next) {
            if (left == right) {
                return true;
            }
            left = left->next;
            right = right->next->next;
        }
        return false;
    }
};



