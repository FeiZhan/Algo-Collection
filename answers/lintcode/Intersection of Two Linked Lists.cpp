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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
		int lengtha(0);
		ListNode *currenta = headA;
		while (currenta) {
			++ lengtha;
			currenta = currenta->next;
		}
		int lengthb(0);
		ListNode *currentb = headB;
		while (currentb) {
			++ lengthb;
			currentb = currentb->next;
		}
		currenta = headA;
		currentb = headB;
		for (int i = min(lengtha, lengthb); i < max(lengtha, lengthb); ++ i) {
			if (lengtha > lengthb) {
				currenta = currenta->next;
			}
			else {
				currentb = currentb->next;
			}
		}
		while (currenta && currentb && currenta != currentb) {
				currenta = currenta->next;
				currentb = currentb->next;
		}
		return (currenta == currentb) ? currenta : NULL;
    }
};
