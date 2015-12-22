//WA

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};
// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        // write your code here
        int size = 0;
        ListNode *temp = head;
        while (temp) {
            ++ size;
            temp = temp->next;
        }
        return sortedListToBST(head, 0, size - 1).first;
    }
    pair<TreeNode *, ListNode *> sortedListToBST(ListNode *head, int begin, int end) {
        if (NULL == head) {
            return make_pair((TreeNode *)(NULL), head);
        }
        else if (begin >= end) {
            return make_pair(new TreeNode(head->val), head);
        }
        int middle = (begin + end) / 2;
        pair<TreeNode *, ListNode *> answer = sortedListToBST(head, begin, middle - 1);
        TreeNode *root = new TreeNode(answer.second->next->val);
        root->left = answer.first;
        pair<TreeNode *, ListNode *> answer1 = sortedListToBST(answer.second->next->next, middle + 1, end);
        root->right = answer1.first;
        return make_pair(root, answer.second->next);
    }
};

int main() {
	// your code goes here
    Solution s;
    //-1->0->1->3->null
    ListNode *head = new ListNode(-1);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    TreeNode *answer = s.sortedListToBST(head);
	return 0;
}
