//@type  Linked List Two Pointers
//@result 21 / 21 test cases passed. Status: Accepted Runtime: 24 ms Submitted: 0 minutes ago You are here! Your runtime beats 71.06% of cpp submissions.

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
    bool isPalindrome(ListNode* head) {
        vector<int> list;
		while (head) {
			list.push_back(head->val);
			head = head->next;
		}
		for (size_t i = 0; i < list.size() / 2; ++ i) {
			if (list[i] != list[list.size() - 1 - i]) {
				return false;
			}
		}
		return true;
    }
};