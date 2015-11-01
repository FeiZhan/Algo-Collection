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
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
		ListNode *left = head;
		ListNode *right = head;
		for (int i = 0; i < n; ++ i) {
			if (NULL == right) {
				return head;
			}
			right = right->next;
		}
		while (left && right && right->next) {
			left = left->next;
			right = right->next;
		}
		// remove head
		if (NULL == right) {
			return head->next;
		}
		left->next = left->next->next;
		return head;
    }
};



