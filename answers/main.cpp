#include <iostream>
#include <climits>
#include <vector>
using namespace std;

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
class ListNode {
	public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
		for (size_t i = 1; i < lists.size(); ++ i) {
			//cout << "test " << (lists[0] ? lists[0]->val : -1) << endl;
			lists[0] = merge2Lists(lists[0], lists[i]);
			//cout << "test " << (lists[0] ? lists[0]->val : -1) << endl;
		}
		return (lists.size() > 0) ? lists[0] : NULL;
    }
	ListNode *merge2Lists(ListNode *list0, ListNode *list1) {
		ListNode *root0 = new ListNode(INT_MAX);
		root0->next = list0;
		ListNode *current0 = root0;
		ListNode *root1 = new ListNode(INT_MAX);
		root1->next = list1;
		ListNode *current1 = root1;
		while (current0->next && current1->next) {
			if (current0->next->val <= current1->next->val) {
				current0 = current0->next;
			}
			else {
				ListNode *temp0 = current0->next;
				ListNode *temp1 = current1->next->next;
				current0->next = current1->next;
				current0->next->next = temp0;
				current1 = temp1;
			}
		}
		if (current1 && current1->next) {
			current0->next = current1->next;
		}
		return root0->next;
	}
};

int main() {
	// your code goes here
	Solution s;
	vector<ListNode *> lists;
	//[2->null,null,-1->null]
	ListNode *node = new ListNode(2);
	lists.push_back(node);
	lists.push_back(NULL);
	node = new ListNode(-1);
	lists.push_back(node);
	ListNode *merged = s.mergeKLists(lists);
	//merged = lists[1];
	while (merged) {
		cout << merged->val << " ";
		merged = merged->next;
	}
	cout << endl;
	return 0;
}