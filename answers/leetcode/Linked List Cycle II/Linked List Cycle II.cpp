//@result 16 / 16 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 0 minutes ago You are here! Your runtime beats 17.12% of cpp submissions.

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
		bool flag = false;
		int count = 0;
		while (fast && fast->next && slow) {
			slow = slow->next;
			fast = fast->next;
			fast = fast->next;
			++ count;
			if (slow == fast) {
				flag = true;
				break;
			}
		}
		if (! flag) {
			return NULL;
		}
		fast = head;
		//@note
		while (fast && slow && fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}
		return slow;
    }
};
