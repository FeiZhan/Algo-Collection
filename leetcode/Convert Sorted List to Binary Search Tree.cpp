/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (NULL == head)
		{
			return NULL;
		}
		std::vector<int> list_vec;
		while (head)
		{
			list_vec.push_back(head->val);
			head = head->next;
		}
		return arrayToBST(list_vec);
    }
    TreeNode *arrayToBST(const std::vector<int> &list_vec)
    {
		if (0 == list_vec.size())
		{
			return NULL;
		}
		if (1 == list_vec.size())
		{
			return new TreeNode(list_vec[0]);
		}
		TreeNode *now = new TreeNode(list_vec[list_vec.size() / 2]);
		std::vector<int> left(list_vec.begin(), list_vec.begin() + list_vec.size() / 2);
		std::vector<int> right(list_vec.begin() + list_vec.size() / 2 + 1, list_vec.end());
		now->left = arrayToBST(left);
		now->right = arrayToBST(right);
		return now;
	}
};
