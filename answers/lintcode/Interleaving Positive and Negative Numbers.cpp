//@result Accepted Total Runtime: 54 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param A: An integer array.
     * @return: void
     */
    void rerange(vector<int> &A) {
        // write your code here
        int count = 0;
        for (size_t i = 0; i < A.size(); ++ i) {
            if (A[i] >= 0) {
                ++ count;
            }
        }
        size_t positive = 0;
        size_t negative = 1;
        if (count * 2 < A.size()) {
            positive = 1;
            negative = 0;
        }
        while (positive < A.size() && negative < A.size()) {
            if (A[positive] < 0 && A[negative] >= 0) {
                int temp = A[positive];
                A[positive] = A[negative];
                A[negative] = temp;
            }
            if (A[positive] >= 0) {
                positive += 2;
            }
            if (A[negative] < 0) {
                negative += 2;
            }
        }
    }
};
