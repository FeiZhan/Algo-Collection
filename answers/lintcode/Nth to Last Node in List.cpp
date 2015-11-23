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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        // write your code here
        ListNode *left = head;
        ListNode *right = head;
        for (int i = 0; i < n; ++ i) {
            if (NULL == right) {
                return NULL;
            }
            right = right->next;
        }
        while (right) {
            left = left->next;
            right = right->next;
        }
        return left;
    }
};
