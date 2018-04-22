/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 2014-04-22 AC, don't create new nodes
//@result 166 / 166 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 4.85% of cpp submissions.

class Solution {
public:
	ListNode *partition(ListNode *head, int x) {
		ListNode *less(new ListNode(0)), *greater(new ListNode(0)), *less_cur(less), *greater_cur(greater), *current(head);
		while (current)
		{
			if (current->val < x)
			{
				less_cur->next = current;
				less_cur = less_cur->next;
			}
			else
			{
				greater_cur->next = current;
				greater_cur = greater_cur->next;
			}
			current = current->next;
		}
		if (less_cur)
		{
			less_cur->next = greater->next;
		}
		// put an end to the multiple connected link
		if (greater_cur)
		{
			greater_cur->next = NULL;
		}
		return less->next;
	}
};
