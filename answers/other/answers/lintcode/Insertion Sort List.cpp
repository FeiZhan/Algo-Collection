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
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        // write your code here
        ListNode *dummy = new ListNode(INT_MAX);
        ListNode *dummy1 = new ListNode(INT_MAX);
        dummy->next = dummy1;
        dummy->next->next = head;
        while (dummy1->next) {
            ListNode *current = dummy1;
            ListNode *max_node = current->next;
            int max_val = INT_MIN;
            while (current && current->next) {
                if (current->next->val >= max_val) {
                    max_val = current->next->val;
                    max_node = current;
                }
                current = current->next;
            }
            ListNode *temp = dummy->next;
            dummy->next = max_node->next;
            max_node->next = max_node->next->next;
            dummy->next->next = temp;
        }
        ListNode *current = dummy;
        while (current && current->next && current->next != dummy1) {
            current = current->next;
        }
        current->next = NULL;
        return dummy->next;
    }
};
