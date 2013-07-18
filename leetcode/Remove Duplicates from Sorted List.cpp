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
        if (NULL == head)
        {
			return head;
		}
        ListNode *parent = head, *current = head->next;
        int current_val = head->val;
        while (current)
        {
			if (current->val == current_val)
			{
				parent->next = current->next;
				delete current;
				current = parent;
			} else
			{
				current_val = current->val;
			}
			// if the current is deleted, the parent does not move
			if (NULL != parent && current != parent)
			{
				parent = parent->next;
			}
			if (NULL != current)
			{
				current = current->next;
			}
		}
		return head;
    }
};
