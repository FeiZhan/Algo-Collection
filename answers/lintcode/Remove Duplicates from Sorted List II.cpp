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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
		if (NULL == head) {
			return NULL;
		}
		bool head_flag = false;
		while (head && head->next && head->next->val == head->val) {
			head_flag = true;
			head->next = head->next->next;
		}
		if (head_flag) {
			return deleteDuplicates(head->next);
		}
		else {
			head->next = deleteDuplicates(head->next);
			return head;
		}
    }
};
