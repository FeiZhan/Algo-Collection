/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * 
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
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        // write your code here
        ListNode *dummy = new ListNode(INT_MAX);
        while (head) {
        	ListNode *temp = head->next;
        	head->next = dummy->next;
        	dummy->next = head;
        	head = temp;
        }
        return dummy->next;
    }
};

