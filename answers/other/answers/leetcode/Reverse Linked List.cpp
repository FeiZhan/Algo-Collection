//@type Linked List
//@result 27 / 27 test cases passed. Status: Accepted Runtime: 68 ms Submitted: 0 minutes ago You are here! Your runtime beats 1.37% of cpp submissions.

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
    ListNode* reverseList(ListNode* head) {
        if (NULL == head || NULL == head->next) {
			return head;
		}
		else {
			ListNode *new_head = reverseList(head->next);
			ListNode *tail = new_head;
			while (tail && tail->next) {
				tail = tail->next;
			}
			tail->next = head;
			head->next = NULL;
			return new_head;
		}
    }
};