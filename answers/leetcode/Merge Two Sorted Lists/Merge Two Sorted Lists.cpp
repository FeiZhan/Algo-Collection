//@result 208 / 208 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago You are here! Your runtime beats 71.34% of cpp submissions.

#include <iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ans = new ListNode(0), *ans_head = ans;
        while (l1 || l2)
        {
			if (! l2 || (l1 && l1->val < l2->val))
			{
				ans->next = l1;
				ans = ans->next;
				l1 = l1->next;
			} else if (! l1 || (l2 && l1->val >= l2->val))
			{
				ans->next = l2;
				ans = ans->next;
				l2 = l2->next;
			}
		}
		return ans_head->next;
    }
};
int main()
{
	ListNode *l1 = NULL, *l2 = NULL, *ans = NULL;
	Solution s;
	l2 = new ListNode(0);
	ans = s.mergeTwoLists(l1, l2);
	cout << "ans: ";
	while (ans)
	{
		cout << " " << ans->val;
		ans = ans->next;
	}
	cout << endl;
	return 0;
}
