//@result 42 / 42 test cases passed. Status: Accepted Runtime: 52 ms Submitted: 0 minutes ago You are here! Your runtime beats 18.32% of cpp submissions.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int alen = 0;
		ListNode *current = headA;
		while (current) {
			++ alen;
			current = current->next;
		}
		int blen = 0;
		current = headB;
		while (current) {
			++ blen;
			current = current->next;
		}
		ListNode *longer = alen >= blen ? headA : headB;
		for (int i = std::min(alen, blen); i < std::max(alen, blen); ++ i) {
			longer = longer->next;
		}
		ListNode *shorter = alen < blen ? headA : headB;
		while (longer && shorter && longer != shorter) {
			longer = longer->next;
			shorter = shorter->next;
		}
		return shorter;
    }
};
