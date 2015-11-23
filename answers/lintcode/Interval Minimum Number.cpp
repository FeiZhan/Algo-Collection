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
        SegmentTreeNode *root = new SegmentTreeNode(0, A.size() * 2);
        for (size_t i = 0; i < A.size(); ++ i) {
            root->add(i, i, A[i]);
        }
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
        int query(int b, int e) {
            int ans = INT_MAX;
            if (b > end || e < begin) {
                return INT_MAX;
            }
            //cout << "debug (" << begin << ", " << end << ") " << value << ": " << b << " " << e << endl;
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
