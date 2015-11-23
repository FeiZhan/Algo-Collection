//@result TLE

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        SegmentTreeNode *root = new SegmentTreeNode(0, 2000);
        for (size_t i = 0; i < A.size(); ++ i) {
            root->add(A[i]);
        }
        vector<int> count_list;
        for (size_t i = 0; i < queries.size(); ++ i) {
            count_list.push_back(root->query(0, queries[i]));
        }
        return count_list;
    }
    class SegmentTreeNode {
    public:
        SegmentTreeNode(int l, int r) : min(l), max(r), value(0), left(NULL), right(NULL) {
            if (min + 1 < max) {
                int middle = (min + max) / 2;
                left = new SegmentTreeNode(min, middle);
                right = new SegmentTreeNode(middle, max);
            }
        }
        int min;
        int max;
        int value;
        SegmentTreeNode *left;
        SegmentTreeNode *right;
        void add(int num) {
            if (num < min || num >= max) {
                return;
            }
            //cout << "debug " << num << " (" << min << ", " << max << ")" << endl;
            ++ value;
            if (left) {
                left->add(num);
            }
            if (right) {
                right->add(num);
            }
        }
        int query(int l, int r) {
            if (l <= min && r >= max) {
                return value;
            }
            else {
                return (left ? left->query(l, r) : 0) + (right ? right->query(l, r) : 0);
            }
        }
    };
};

#include <iostream>
using namespace std;

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that 
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        // write your code here
        vector<int> count_list;
        sort(A.begin(), A.end());
        for (size_t i = 0; i < queries.size(); ++ i) {
            size_t left = 0;
            size_t right = A.size() - 1;
            bool flag = false;
            while (left <= right && right < A.size()) {
                size_t middle = (left + right) / 2;
                if (A[middle] == queries[i]) {
                    if (0 == middle || A[middle - 1] != queries[i]) {
                        flag = true;
                        break;
                    }
                    else {
                        right = middle - 1;
                    }
                }
                else if (A[middle] > queries[i]) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }
            }
            size_t pos = (left + right) / 2 + ! flag;
            count_list.push_back(pos);
        }
        return count_list;
    }
};

int main() {
    // your code goes here
    Solution s;
    vector<int> ans = s.countOfSmallerNumber(A, queries);
    return 0;
}