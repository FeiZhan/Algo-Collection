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
     * @param k an integer
     * @return a ListNode
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Write your code here
        ListNode *dummy = new ListNode(INT_MAX);
        int count = 0;
        while (count < k && head) {
            ListNode *temp = head->next;
            head->next = dummy->next;
            dummy->next = head;
            head = temp;
            ++ count;
        }
        if (count < k && INT_MAX != k) {
            dummy->next = reverseKGroup(dummy->next, INT_MAX);
        }
        if (head) {
            ListNode *temp = dummy;
            while (temp && temp->next) {
                temp = temp->next;
            }
            if (temp) {
                temp->next = reverseKGroup(head, k);
            }
        }
        return dummy->next;
    }
};
