//@result Accepted Total Runtime: 32 ms 100% test cases passed.

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
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        // Write your code here
		if (NULL == head) {
			return NULL;
		}
		else if (head->val == val) {
			return removeElements(head->next, val);
		}
		else {
			head->next = removeElements(head->next, val);
			return head;
		}
    }
};
