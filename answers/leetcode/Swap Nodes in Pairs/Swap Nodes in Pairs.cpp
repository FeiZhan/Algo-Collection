//@result 55 / 55 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 2.50% of cpp submissions.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (NULL == head || NULL == head->next)
		{
			return head;
		}
		ListNode *tail = swapPairs(head->next->next);
		ListNode *new_head = head->next;
		new_head->next = head;
		new_head->next->next = tail;
		return new_head;
    }
};
