//@result 81 / 81 test cases passed. Status: Accepted Runtime: 28 ms Submitted: 3 minutes ago You are here! Your runtime beats 10.36% of cpp submissions.

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if (NULL == head || k <= 1) {
			return head;
		}
		ListNode *new_head = new ListNode(0);
		new_head->next = head;
		ListNode *current = new_head;
		while (current) {
			current = reverseNodes(current, k);
		}
		return new_head->next;
    }
    ListNode *reverseNodes(ListNode *dull, int k) {
		ListNode *current = dull;
		for (int i = 0; i < k; ++ i) {
			if (NULL == current) {
				break;
			}
			current = current->next;
		}
		if (NULL == current) {
			return NULL;
		}
		current = dull->next;
		ListNode *next = current->next;
		ListNode *next2 = current->next->next;
		for (int i = 0; i < k - 1; ++ i) {
			next->next = current;
			current = next;
			next = next2;
			if (NULL == next2) {
				break;
			}
			next2 = next2->next;
		}
		next2 = dull->next;
		dull->next->next = next;
		dull->next = current;
		return next2;
	}
};
