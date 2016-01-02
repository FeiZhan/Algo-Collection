class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        // write your code here
        for (size_t i = 0; i < A.size(); ++ i) {
            if (A[i] > 0 && A[i] <= A.size() && A[i] != i + 1 && A[A[i] - 1] != A[i]) {
                swap(A[i], A[A[i] - 1]);
                -- i;
            }
        }
        for (size_t i = 0; i < A.size(); ++ i) {
            if (A[i] != i + 1) {
                return i + 1;
            }
        }
        return A.size() + 1;
    }
};
