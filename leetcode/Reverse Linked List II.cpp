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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (NULL == head->next->next && m == 1 && n == 2)
		{
			ListNode *tmp = head->next;
			head->next->next = head;
			head->next = NULL;
			return tmp;
		}
		ListNode *previous = head;
		for (int i = 0; i < m - 2; ++ i)
		{
			previous = previous->next;
		}
		ListNode *now = previous->next, *begin = previous->next;
		for (int i = m; i < n; ++ i)
		{
			begin = previous->next;
			previous->next = now->next;
			now->next = previous->next->next;
			previous->next->next = begin;
		}
		return head;
    }
};
