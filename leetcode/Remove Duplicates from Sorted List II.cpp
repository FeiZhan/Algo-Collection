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
