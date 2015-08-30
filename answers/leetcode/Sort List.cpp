
class Solution {
public:
    ListNode *sortList(ListNode *head) {
		if (NULL == head || NULL == head->next)
		{
			return head;
		}
		ListNode *tail = head, *half = head;
		while (NULL != tail && NULL != tail->next)
		{
			tail = tail->next;
			if (NULL == tail || NULL == tail->next)
			{
				break;
			}
			tail = tail->next;
			half = half->next;
		}
		ListNode *head0 = sortList(half->next);
		half->next = NULL;
		ListNode *head1 = sortList(head);
		ListNode *dull(new ListNode(0)), *current = dull, *current0 = head0, *current1 = head1;
		while (current != NULL && (current0 != NULL || current1 != NULL))
		{
			if (NULL != current0)
			{
				current->next = current0;
			}
			else
			{
				current->next = current1;
			}
			if (NULL != current1 && current1->val <= current->next->val)
			{
				current->next = current1;
				current1 = current1->next;
			} else
			{
				current0 = current0->next;
			}
			current = current->next;
		}
		return dull->next;
    }
};
