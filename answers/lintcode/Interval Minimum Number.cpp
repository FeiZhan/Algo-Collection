//@result TLE

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        // write your code here
        vector<int> min_list;
        SegmentTreeNode *root = new SegmentTreeNode(0, A.size() - 1);
        for (size_t i = 0; i < A.size(); ++ i) {
            root->add(i, i, A[i]);
        }
        //root->build(0, A.size() - 1, A);
        for (size_t i = 0; i < queries.size(); ++ i) {
            int temp = root->query(queries[i].start, queries[i].end);
            min_list.push_back(temp);
        }
        return min_list;
    }
    class SegmentTreeNode {
    public:
        int value;
        int begin;
        int end;
        SegmentTreeNode *left;
        SegmentTreeNode *right;
        SegmentTreeNode(int b, int e) : value(INT_MAX), begin(b), end(e), left(NULL), right(NULL) {}
        void add(int b, int e, int v) {
            if (b > end || e < begin) {
                return;
            }
            value = min(value, v);
            if (begin < end) {
                int middle = (begin + end) / 2;
                if (e <= middle) {
                    if (! left) {
                        left = new SegmentTreeNode(begin, middle);
                    }
                    left->add(b, e, v);
                }
                if (b > middle) {
                    if (! right) {
                        right = new SegmentTreeNode(middle + 1, end);
                    }
                    right->add(b, e, v);
                }
            }
        }
        void build(size_t b, size_t e, const vector<int> &nums) {
            if (b > e || e >= nums.size()) {
                return;
            }
            else if (b == e) {
                value = nums[b];
            }
            else {
                left = new SegmentTreeNode(b, (b + e) / 2);
                left->build(b, (b + e) / 2, nums);
                right = new SegmentTreeNode((b + e) / 2 + 1, e);
                right->build((b + e) / 2 + 1, e, nums);
                value = min(left->value, right->value);
            }
        }
        int query(int b, int e) {
            int ans = INT_MAX;
            if (b > end || e < begin) {
                return ans;
            }
            if (b <= begin && e >= end) {
                ans = min(ans, value);
            }
            if (left) {
                ans = min(ans, left->query(b, e));
            }
            if (right) {
                ans = min(ans, right->query(b, e));
            }
            return ans;
        }
    };
};
