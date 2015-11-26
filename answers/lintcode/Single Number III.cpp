class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        // write your code here
        int xor_num = 0;
        for (size_t i = 0; i < A.size(); ++ i) {
            xor_num ^= A[i];
        }
        xor_num &= ~(xor_num - 1);
        vector<int> ans(2, 0);
        for (size_t i = 0; i < A.size(); ++ i) {
            if (A[i] & xor_num) {
                ans[1] ^= A[i];
            }
            else {
                ans[0] ^= A[i];
            }
        }
        return ans;
    }
};
