//@level Easy 
//@type Cracking The Coding Interview Linked List High Precision
//@result Accepted Total Runtime: 14 ms 100% test cases passed.

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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
		int carry(0);
		ListNode *ans = new ListNode(0);
		ListNode *current = ans;
		while (l1 || l2 || carry) {
			if (l1) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				carry += l2->val;
				l2 = l2->next;
			}
			current->val = carry % 10;
			carry /= 10;
			// avoid extra zero
			if (l1 || l2 || carry) {
				current->next = new ListNode(0);
			}
			current = current->next;
		}
		return ans;
    }
};

int main() {
	// your code goes here
	Solution s;
	ListNode *l1 = new ListNode(3);
	l1->next = new ListNode(1);
	l1->next->next = new ListNode(5);
	ListNode *l2 = new ListNode(3);
	l2->next = new ListNode(1);
	l2->next->next = new ListNode(5);
	ListNode *ans = s.addLists(l1, l2);
	while (ans) {
		cout << ans->val << " ";
		ans = ans->next;
	}
	cout << endl;
	return 0;
}