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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == head)
        {
    		return head;
		}
        int length = 1;
		ListNode *end = head;
		while (end->next)
		{
			length ++;
			end = end->next;
		}
		if (0 == length)
		{
			return head;
		}
		k = k % length;
		if (0 == k)
		{
			return head;
		}
		ListNode *new_end = head;
		for (int i = 0; i < length - k - 1; ++ i)
		{
			new_end = new_end->next;
		}
		ListNode *new_head = new_end->next;
		end->next = head;
		new_end->next = NULL;
		return new_head;
    }
};
