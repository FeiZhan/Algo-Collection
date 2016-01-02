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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
		ListNode *less_head = new ListNode(INT_MAX);
		ListNode *less = less_head;
		ListNode *greater_head = new ListNode(INT_MAX);
		ListNode *greater = greater_head;
		while (head) {
			if (head->val < x) {
				less->next = head;
				less = less->next;
			}
			else {
				greater->next = head;
				greater = greater->next;
			}
			ListNode *temp = head;
			head = head->next;
			temp->next = NULL;
		}
		less->next = greater_head->next;
		return less_head->next;
    }
};



