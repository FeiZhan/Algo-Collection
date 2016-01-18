//@result Accepted Total Runtime: 12 ms 100% test cases passed.

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        long long index = 1;
        long long position = 1;
        long long factor = 1;
        for (size_t i = A.size() - 1; i < A.size(); -- i) {
            long long count = 0;
            for (size_t j = i + 1; j < A.size(); ++ j) {
                if (A[i] > A[j]) {
                    ++ count;
                }
            }
            index += count * factor;
            factor *= position;
            ++ position;
        }
        return index;
    }
};
