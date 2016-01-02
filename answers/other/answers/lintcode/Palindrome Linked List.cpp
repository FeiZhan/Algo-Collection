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
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        vector<int> value_list;
        while (head) {
            value_list.push_back(head->val);
            head = head->next;
        }
        for (size_t i = 0; i * 2 < value_list.size(); ++ i) {
            if (value_list[i] != value_list[value_list.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
