//@level Medium 
//@type LintCode Copyright Binary Tree Segment Tree
//@result Accepted Total Runtime: 1311 ms 100% test cases passed.

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
		if (NULL == root || end < root->start || root->end < start) {
			return 0;
		}
		else if (start <= root->start && root->end <= end) {
			return root->count;
		}
		else {
			return query(root->left, start, end) + query(root->right, start, end);
		}
    }
};
