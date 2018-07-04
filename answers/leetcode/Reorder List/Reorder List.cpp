// http://fisherlei.blogspot.ca/2013/11/leetcode-reorder-list-solution.html
//@result 13 / 13 test cases passed. Status: Accepted Runtime: 60 ms Submitted: 0 minutes ago You are here! Your runtime beats 91.05% of cpp submissions.

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
    void reorderList(ListNode *head) {
		if (NULL == head) {
			return;
		}
		ListNode *fast = head, *slow = head;
		while (fast) {
			fast = fast->next;
			if (fast) {
				fast = fast->next;
				if (fast) {
					slow = slow->next;
				}
			}
		}
		if (NULL == slow) {
			return;
		}
		ListNode *current = slow;
		ListNode *previous = slow->next;
		current->next = NULL;
		while (previous) {
			ListNode *temp = previous->next;
			previous->next = current;
			current = previous;
			previous = temp;
		}
		ListNode *first = head;
		ListNode *second = current;
		while (first && second && first != second) {
			ListNode *temp = second->next;
			second->next = first->next;
			first->next = second;
			first = second->next;
			second = temp;
		}
    }
};
