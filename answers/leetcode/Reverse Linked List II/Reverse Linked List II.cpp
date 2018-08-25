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

// 2015-1-3
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
		ListNode *dummy = new ListNode(INT_MAX);
		dummy->next = head;
		ListNode *tail = dummy;
		for (int i = 1; i < m; ++ i) {
			tail = tail->next;
		}
		if (NULL == tail) {
			return head;
		}
		ListNode *left = tail->next;
		ListNode *right = tail->next;
		for (int i = m; i < n; ++ i) {
			right = right->next;
		}
		ListNode *tail1 = right->next;
		ListNode *prev = left;
		if (NULL == prev) {
			return head;
		}
		ListNode *current = prev->next;
		if (NULL == current) {
			return head;
		}
		ListNode *next = current->next;
		while (current && prev != right) {
			//cout << "revert " << current->val << endl;
			current->next = prev;
			prev = current;
			current = next;
			next = next ? next->next : NULL;
		}
		tail->next = right;
		left->next = tail1;
		return dummy->next;
	}
};
