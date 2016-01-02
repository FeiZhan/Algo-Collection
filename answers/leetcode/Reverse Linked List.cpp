//@type Linked List
//@algorithm recursive
//@result 27 / 27 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 15.22% of cpp submissions.

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
    ListNode* reverseList(ListNode* head) {
        if (NULL == head || NULL == head->next) {
			return head;
		}
		else {
			ListNode *new_head = reverseList(head->next);
            // don't have to find the tail of new list
			head->next->next = head;
			head->next = NULL;
			return new_head;
		}
    }
};

//@algorithm iterative
//@result 27 / 27 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 15.22% of cpp submissions.

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
    ListNode* reverseList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MAX);
        while (head) {
            ListNode *temp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = temp;
        }
        return dummy->next;
    }
};
