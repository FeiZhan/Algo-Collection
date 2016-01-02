ListNode *addLists(ListNode *l1, listNode *l2, int carry)
{
	if (NULL == l1 && NULL == l2)
	{
		return NULL;
	}
	ListNode *result = new ListNode(carry, NULL);
	if (NULL != l1)
	{
		result->data += l1->data;
	}
	if (NULL != l2)
	{
		result->data += l2->data;
	}
	carry = result->data / 10;
	result->data %= 10;
	result->next = addLists(NULL == l1 ? NULL : l1->next, NULL == l2 ? NULL : l2->next, carry);
	return result;
}
