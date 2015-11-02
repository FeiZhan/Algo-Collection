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
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (NULL == head) {
        	return head;
        }
        cout << "test " << head->val << endl;
        ListNode *left = head;
        ListNode *right = head;
        while (left && right && right->next) {
        	left = left->next;
        	right = right->next->next;
        }
        right = left->next;
        left->next = NULL;
        left = sortList(head);
        right = sortList(right);
        head = new ListNode(INT_MAX);
        ListNode *current = head;
        while (left || right) {
        	if (left && right) {
        		if (left->val < right->val) {
        			current->next = left;
        			left = left->next;
        		}
        		else {
        			current->next = right;
        			right = right->next;
        		}
        	}
        	else if (left) {
    			current->next = left;
    			left = left->next;
        	}
        	else {
    			current->next = right;
    			right = right->next;
        	}
        	current = current->next;
        	current->next = NULL;
        }
        return head->next;
    }
};



