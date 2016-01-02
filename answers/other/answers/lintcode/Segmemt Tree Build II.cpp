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
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        // write your code here
        return build(0, A.size() - 1, A);
    }
    SegmentTreeNode *build(size_t start, size_t end, const std::vector<int> &A) {
        if (start > end || end >= A.size()) {
            return NULL;
        }
        SegmentTreeNode *root = new SegmentTreeNode(start, end, A[start]);
        if (start < end) {
            root->left = build(start, (start + end) / 2, A);
            root->right = build((start + end) / 2 + 1, end, A);
            root->max = max(root->max, max( (root->left ? root->left->max : INT_MIN), (root->right ? root->right->max : INT_MIN) ));
        }
        return root;
    }
};
