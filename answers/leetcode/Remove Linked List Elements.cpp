//@type Linked List
//@result 63 / 63 test cases passed. Status: Accepted Runtime: 32 ms Submitted: 0 minutes ago You are here! Your runtime beats 60.24% of cpp submissions.

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
    ListNode* removeElements(ListNode* head, int val) {
        if (NULL == head) {
			return head;
		}
		else if (val == head->val) {
			return removeElements(head->next, val);
		}
		else {
			head->next = removeElements(head->next, val);
			return head;
		}
    }
};