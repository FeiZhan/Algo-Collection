/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        ListNode *dummy = new ListNode(INT_MAX);
        dummy->next = head;
        ListNode *left = dummy;
        ListNode *right = dummy;
        for (size_t i = m; i <= n + 1; ++ i) {
        	if (NULL == right) {
        		break;
        	}
        	right = right->next;
        }
        for (size_t i = 1; i < m; ++ i) {
        	if (left) {
        		left = left->next;
        	}
        	if (right) {
        		right = right->next;
        	}
        }
        if (left) {
		left->next = reverse(left->next, right);
        }
        return dummy->next;
    }
    ListNode *reverse(ListNode *head, ListNode *tail) {
        // write your code here
        ListNode *dummy = new ListNode(INT_MAX);
        while (head && head != tail) {
        	ListNode *temp = head->next;
        	head->next = dummy->next;
        	dummy->next = head;
        	head = temp;
        }
        if (tail) {
        	ListNode *temp = dummy;
        	while (temp && temp->next) {
        		temp = temp->next;
        	}
        	if (temp) {
        		temp->next = tail;
        	}
        }
        return dummy->next;
    }
};

