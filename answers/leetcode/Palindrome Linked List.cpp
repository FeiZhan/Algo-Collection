//@type Linked List Two Pointers
//@time complexity O(n)
//@space complexity O(1)
//@result 21 / 21 test cases passed. Status: Accepted Runtime: 28 ms Submitted: 0 minutes ago You are here! Your runtime beats 10.84% of cpp submissions.

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
        ListNode *left = head;
        ListNode *right = head;
        while (right && right->next) {
            left = left->next;
            right = right->next->next;
        }
        ListNode *dummy = new ListNode(INT_MAX);
        while (left) {
            ListNode *temp = left->next;
            left->next = dummy->next;
            dummy->next = left;
            left = temp;
        }
        left = head;
        right = dummy->next;
        while (left && right) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};
