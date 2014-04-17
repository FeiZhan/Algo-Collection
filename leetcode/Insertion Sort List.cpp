class Solution {
public:
	ListNode *insertionSortList(ListNode *head) {
		if (NULL == head)
		{
			return head;
		}
		ListNode *parent = head, *dull(new ListNode(INT_MIN));
		dull->next = head;
		while (NULL != parent && NULL != parent->next)
		{
			ListNode *target = parent->next;
			ListNode *insert = dull;
			while (NULL != insert && NULL != insert->next && insert->next->val < target->val)
			{
				insert = insert->next;
			}
			if (NULL == insert)
			{
				break;
			}
			if (insert->next != target)
			{
				ListNode *temp = insert->next;
				insert->next = target;
				parent->next = target->next;
				target->next = temp;
			}
			else // if inserted, do not increase iterator
			{
				parent = parent->next;
			}
		}
		return dull->next;
	}
};