//@result 70 / 70 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head = new ListNode(INT_MAX);
        ListNode *odd = odd_head;
        ListNode *even_head = new ListNode(INT_MAX);
        ListNode *even = even_head;
        bool odd_flag = true;
        while (head) {
            if (odd_flag) {
                odd->next = head;
                head = head->next;
                odd = odd->next;
                odd->next = NULL;
            }
            else {
                even->next = head;
                head = head->next;
                even = even->next;
                even->next = NULL;
            }
            odd_flag = ! odd_flag;
        }
        odd->next = even_head->next;
        return odd_head->next;
    }
};
