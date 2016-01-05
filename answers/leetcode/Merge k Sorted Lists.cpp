//@result 130 / 130 test cases passed. Status: Accepted Runtime: 424 ms Submitted: 0 minutes ago You are here! Your runtime beats 40.18% of cpp submissions.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp = [] (ListNode *&a, ListNode *&b) -> bool {
            return a->val > b->val;
        };
        std::priority_queue<ListNode *, std::vector<ListNode *>, decltype(comp)> heap(comp);
        for (size_t i = 0; i < lists.size(); ++ i) {
            if (lists[i]) {
                heap.push(lists[i]);
            }
        }
        ListNode *dummy = new ListNode(INT_MAX);
        ListNode *current = dummy;
        while (! heap.empty()) {
            current->next = heap.top();
            heap.pop();
            current = current->next;
            if (current->next) {
                heap.push(current->next);
            }
            current->next = NULL;
        }
        return dummy->next;
    }
};
