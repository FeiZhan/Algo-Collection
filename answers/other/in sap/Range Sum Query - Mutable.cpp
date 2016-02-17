    class SegmentTreeNode {
    public:
        int min;
        int max;
        int value;
        SegmentTreeNode *left;
        SegmentTreeNode *right;
        SegmentTreeNode(const vector<int> &nums, int _min, int _max) : min(_min), max(_max), value(0), left(NULL), right(NULL) {
            if (_min == _max) {
                value = nums[_min];
            }
            else if (min < _max) {
                int middle = (min + max) / 2;
                left = new SegmentTreeNode(nums, _min, middle);
                right = new SegmentTreeNode(nums, middle + 1, _max);
                value = left->value + right->value;
            }
        }
        int getRange(int i, int j) {
            int val = 0;
            if (i <= min && max <= j) {
                val = value;
            }
            else if (i <= max && min <= j) {
                if (left) {
                    val += left->getRange(i, j);
                }
                if (right) {
                    val += right->getRange(i, j);
                }
            }
            return val;
        }
        void update(int i, int val) {
            if (min == i && max == i) {
                value = val;
            }
            else if (min <= i && max >= i) {
                int v = 0;
                if (left) {
                    left->update(i, val);
                    v += left->value;
                }
                if (right) {
                    right->update(i, val);
                    v += right->value;
                }
                value = v;
            }
        }
    };
class NumArray {
public:
    SegmentTreeNode *root;
    NumArray(vector<int> &nums) : root(new SegmentTreeNode(nums, 0, nums.size() - 1)) {
    }

    void update(int i, int val) {
        if (root) {
            root->update(i, val);
        }
    }

    int sumRange(int i, int j) {
        return root ? root->getRange(i, j) : 0;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);