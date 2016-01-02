class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        // write your code here
        int ans = 0;
        for (size_t i = 0; i < A.size(); ++ i) {
        	ans ^= A[i];
        }
        return ans;
    }
};

