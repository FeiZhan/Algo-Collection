//@result WA, leetcode AC

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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        // write your code here
		if (NULL == head || 0 == k) {
			return head;
		}
		ListNode *left = head;
		ListNode *right = head;
		for (int i = 0; i < k; ++ i) {
			if (NULL == right) {
				k %= i;
				break;
			}
			right = right->next;
		}
		if (NULL == right) {
			right = head;
			for (int i = 0; i < k; ++ i) {
				if (NULL == right) {
					return head;
				}
				right = right->next;
			}
		}
		while (left && left->next && right && right->next) {
			left = left->next;
			right = right->next;
		}
		if (NULL == left || NULL == right) {
			return head;
		}
		right->next = head;
		ListNode *new_head = left->next;
		left->next = NULL;
		return new_head;
    }
};
