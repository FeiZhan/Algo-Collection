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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (NULL == head || NULL == head->next)
		{
			return head;
		}
		if (head->val == head->next->val)
		{
			ListNode *now = head;
			while (now && now->val == head->val)
			{
				now = now->next;
			}
			return deleteDuplicates(now);
		} else
		{
			head->next = deleteDuplicates(head->next);
			return head;
		}
    }
};

// 2014-12-24
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
    ListNode *deleteDuplicates(ListNode *head) {
		ListNode *dumb = new ListNode(INT_MAX);
		dumb->next = head;
		ListNode *current = dumb;
		while (current) {
			if (current->next && current->next->next && current->next->val == current->next->next->val) {
				ListNode *new_val = current->next;
				while (new_val && new_val->val == current->next->val) {
					new_val = new_val->next;
				}
				current->next = new_val;
			} else {
				current = current->next;
			}
		}
		return dumb->next;
    }
};
