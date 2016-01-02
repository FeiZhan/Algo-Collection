//@type Linked List
//@result 83 / 83 test cases passed. Status: Accepted Runtime: 16 ms Submitted: 1 minute ago You are here! Your runtime beats 9.05% of cpp submissions.

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
    void deleteNode(ListNode* node) {
        if (NULL == node) {
		}
        if (NULL == node->next) {
			node = NULL;
		}
		else {
			node->val = node->next->val;
			node->next = node->next->next;
		}
    }
};