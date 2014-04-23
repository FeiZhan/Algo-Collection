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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *less = new ListNode(0), *more = new ListNode(0), *more_head = more, *less_head = less, *now = head;
        while (now)
        {
			if (now->val < x)
			{
				less->next = new ListNode(now->val);
				less = less->next;
			} else
			{
				more->next = new ListNode(now->val);
				more = more->next;
			}
			now = now->next;
		}
		less->next = more_head->next;
		return less_head->next;
    }
};
// 2014-04-22 AC, don't create new nodes
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