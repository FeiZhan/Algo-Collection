// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
// check if fast is the same with slow
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (NULL == head)
		{
			return false;
		}
		ListNode *slow(head), *fast(head->next);
		bool has_cycle = false;
		while (NULL != slow && NULL != fast)
		{
			if (slow == fast)
			{
				has_cycle = true;
				break;
			}
			slow = slow->next;
			fast = fast->next;
			if (NULL == fast)
			{
				break;
			}
			fast = fast->next;
		}
		return has_cycle;
	}
};