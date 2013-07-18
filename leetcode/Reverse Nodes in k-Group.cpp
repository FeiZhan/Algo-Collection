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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (NULL == head)
        {
			return head;
		}
        ListNode *current = head;
        vector<ListNode *> vec;
        for (int i = 0; i < k; ++ i)
        {
			if (NULL == current)
			{
				return head;
			}
			vec.push_back(current);
			current = current->next;
		}
		ListNode *child = reverseKGroup(vec[k - 1]->next, k);
		for (int i = k - 1; i >= 1; -- i)
		{
			vec[i]->next = vec[i - 1];
		}
		vec[0]->next = child;
		return vec[k - 1];
    }
};
