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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *pos1 = l1, *pos2 = l2, *ans = new ListNode(0), *ans_pos = ans;
        int carry = 0;
        while (pos1 && pos2)
        {
			int value = pos1->val + pos2->val + carry;
			ans_pos->val = value % 10;
			carry = value / 10;
			pos1 = pos1->next;
			pos2 = pos2->next;
			if (pos1 || pos2 || carry)
			{
				ans_pos->next = new ListNode(0);
				ans_pos = ans_pos->next;
			}
		}
		while (pos1)
		{
			int value = pos1->val + carry;
			ans_pos->val = value % 10;
			carry = value / 10;
			pos1 = pos1->next;
			if (pos1 || pos2 || carry)
			{
				ans_pos->next = new ListNode(0);
				ans_pos = ans_pos->next;
			}
		}
		while (pos2)
		{
			int value = pos2->val + carry;
			ans_pos->val = value % 10;
			carry = value / 10;
			pos2 = pos2->next;
			if (pos1 || pos2 || carry)
			{
				ans_pos->next = new ListNode(0);
				ans_pos = ans_pos->next;
			}
		}
		while (carry)
		{
			int value = carry;
			ans_pos->val = value % 10;
			carry = value / 10;
			if (carry)
			{
				ans_pos->next = new ListNode(0);
				ans_pos = ans_pos->next;
			}
		}
		return ans;
    }
};
