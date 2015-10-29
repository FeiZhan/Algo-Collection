//@result Accepted Total Runtime: 78 ms 100% test cases passed.

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
		return sortedArrayToBST(A, 0, A.size() - 1);
    }
    TreeNode *sortedArrayToBST(const vector<int> &array, size_t begin, size_t end) {
		if (begin > end || end >= array.size()) {
			return NULL;
		}
		size_t middle = (begin + end) / 2;
		TreeNode *current = new TreeNode(array[middle]);
		current->left = sortedArrayToBST(array, begin, middle - 1);
		current->right = sortedArrayToBST(array, middle + 1, end);
		return current;
	}
};



