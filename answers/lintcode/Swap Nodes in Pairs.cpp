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
     * @return a ListNode
     */
    ListNode* swapPairs(ListNode* head) {
        // Write your code here
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode *second = head->next;
        head->next = swapPairs(second->next);
        second->next = head;
        return second;
    }
};
