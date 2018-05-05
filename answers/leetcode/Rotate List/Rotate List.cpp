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

// 2015-1-3
//@result 230 / 230 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 8.96% of cpp submissions.

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
		if (NULL == head || NULL == head->next) {
			return head;
		}
		ListNode *current = head;
		int length = 1;
		while (current->next) {
			++ length;
			current = current->next;
		}
		current->next = head;
		for (int i = 0; i < length - k % length; ++ i) {
			current = current->next;
		}
		head = current->next;
		current->next = NULL;
		return head;
	}
};
