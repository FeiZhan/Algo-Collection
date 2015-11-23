class Solution {
public:
    /* you may need to use some attributes here */


    /**
     * @param A: An integer vector
     */
    Solution(vector<int> A) : value_list(A), root(new SegmentTreeNode(0, A.size() * 2)) {
        // write your code here
        for (size_t i = 0; i < A.size(); ++ i) {
            root->add(i, A[i]);
        }
    }

    /**
     * @param start, end: Indices
     * @return: The sum from start to end
     */
    long long query(int start, int end) {
        // write your code here
        return root->query(start, end);
    }

    /**
     * @param index, value: modify A[index] to value.
     */
    void modify(int index, int value) {
        // write your code here
        root->add(index, value - value_list[index]);
    }

    vector<int> value_list;
    class SegmentTreeNode {
    public:
        size_t begin;
        size_t end;
        int value;
        SegmentTreeNode *left;
        SegmentTreeNode *right;
        SegmentTreeNode(size_t b, size_t e) : begin(b), end(e), value(0), left(NULL), right(NULL) {}
        void add(size_t index, int v) {
            if (index <= end && index >= begin) {
                value += v;
                size_t middle = (begin + end) / 2;
                if (begin < end) {
                    if (index <= middle) {
                        if (! left) {
                            left = new SegmentTreeNode(begin, middle);
                        }
                        left->add(index, v);
                    }
                    else {
                        if (! right) {
                            right = new SegmentTreeNode(middle + 1, end);
                        }
                        right->add(index, v);
                    }
                }
            }
        }
        long long query(size_t b, size_t e) {
            if (b > end || e < begin) {
                return 0;
            }
            else if (b <= begin && e >= end) {
                return value;
            }
            else {
                int sum = 0;
                if (left) {
                    sum += left->query(b, e);
                }
                if (right) {
                    sum += right->query(b, e);
                }
                return sum;
            }
        }
    } *root;
};
