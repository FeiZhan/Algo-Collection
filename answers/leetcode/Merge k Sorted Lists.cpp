// exist better solutions
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		ListNode *head = new ListNode(0), *now = head;
		vector<ListNode *> nows(lists);
		bool change;
		do
		{
			int min = INT_MAX, min_pos = -1;
			for (int i = 0; i < nows.size(); ++ i)
			{
				if (nows[i] != NULL && nows[i]->val < min)
				{
					min = nows[i]->val;
					min_pos = i;
				}
			}
			change = false;
			if (min_pos >= 0 && nows[min_pos] != NULL)
			{
				change = true;
				nows[min_pos] = nows[min_pos]->next;
				now->next = new ListNode(min);
				now = now->next;
			}
		} while (change);
		return head->next;
    }
};
