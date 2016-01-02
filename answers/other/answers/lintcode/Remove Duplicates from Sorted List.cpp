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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
		if (NULL == head || NULL == head->next) {
			return head;
		}
		else if (head->val == head->next->val) {
			head->next = head->next->next;
			return deleteDuplicates(head);
		}
		else {
			head->next = deleteDuplicates(head->next);
			return head;
		}
    }
};
