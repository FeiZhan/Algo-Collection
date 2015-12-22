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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        ListNode *dummy = new ListNode(INT_MAX);
        for (size_t i = 0; i < lists.size(); ++ i) {
            for (ListNode *current = dummy, *ith = lists[i]; current && ith;) {
                if (NULL == current->next || current->next->val > ith->val) {
                    ListNode *temp = ith->next;
                    ith->next = current->next;
                    current->next = ith;
                    ith = temp;
                }
                else {
                    current = current->next;
                }
            }
        }
        return dummy->next;
    }
};
