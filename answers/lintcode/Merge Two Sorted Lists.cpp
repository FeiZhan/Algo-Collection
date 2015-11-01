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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // write your code here
		ListNode *head = new ListNode(INT_MAX);
		ListNode *current = head;
		while (l1 || l2) {
			current->next = new ListNode(INT_MAX);
			if ((l1 && l2 && l1->val <= l2->val) || NULL == l2) {
				current->next->val = l1->val;
				l1 = l1->next;
			}
			else if ((l1 && l2 && l1->val > l2->val) || NULL == l1) {
				current->next->val = l2->val;
				l2 = l2->next;
			}
			current = current->next;
		}
		return head->next;
    }
};
