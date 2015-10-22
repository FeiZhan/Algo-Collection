//@level Medium 
//@type LintCode Copyright Binary Tree Segment Tree
//@result Accepted Total Runtime: 5368 ms 100% test cases passed.

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
		if (NULL == root) {
			return 0;
		}
		else if (start <= root->start && root->end <= end) {
			return root->max;
		}
		else {
			return max(query(root->left, start, end), query(root->right, start, end));
		}
    }
};
