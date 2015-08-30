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

// 2014-12-14
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if (NULL == head || k <= 1) {
			return head;
		}
		ListNode *new_head = new ListNode(0);
		new_head->next = head;
		ListNode *current = new_head;
		while (current) {
			current = reverseNodes(current, k);
		}
		return new_head->next;
    }
    ListNode *reverseNodes(ListNode *dull, int k) {
		ListNode *current = dull;
		for (int i = 0; i < k; ++ i) {
			if (NULL == current) {
				break;
			}
			current = current->next;
		}
		if (NULL == current) {
			return NULL;
		}
		current = dull->next;
		ListNode *next = current->next;
		ListNode *next2 = current->next->next;
		for (int i = 0; i < k - 1; ++ i) {
			next->next = current;
			current = next;
			next = next2;
			if (NULL == next2) {
				break;
			}
			next2 = next2->next;
		}
		next2 = dull->next;
		dull->next->next = next;
		dull->next = current;
		return next2;
	}
};
