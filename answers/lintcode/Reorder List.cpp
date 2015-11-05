/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (NULL == head || NULL == head->next) {
            return;
        }
        ListNode *left = head;
        ListNode *right = head;
        while (left && right && right->next && right->next->next) {
            left = left->next;
            right = right->next->next;
        }
        right = reverse(left->next);
        left->next = NULL;
        left = head;
        head = new ListNode(INT_MAX);
        ListNode *current = head;
        bool merge_flag = true;
        while (left || right) {
            if (merge_flag || NULL == right) {
                current->next = left;
                left = left->next;
            }
            else if (! merge_flag || NULL == left) {
                current->next = right;
                right = right->next;
            }
            current = current->next;
            current->next = NULL;
            merge_flag = ! merge_flag;
        }
        head = head->next;
    }
    ListNode *reverse(ListNode *head) {
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



