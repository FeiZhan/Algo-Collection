class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        A.resize(A.size() + B.size());
        A.insert(A.end(), B.begin(), B.end());
        sort(A.begin(), A.end());
        if (A.size() % 2) {
            return A[(A.size() - 1) / 2];
        }
        else {
            return (A[A.size() / 2] + A[A.size() / 2 + 2]) / 2.0;
        }
    }
};
