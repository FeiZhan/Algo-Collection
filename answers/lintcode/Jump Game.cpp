class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
		vector<bool> dp(A.size(), false);
		dp[0] = true;
		for (size_t i = 0; i < dp.size(); ++ i) {
			if (dp[i]) {
				for (size_t j = 1; j <= A[i] && i + j < dp.size(); ++ j) {
					dp[i + j] = true;
				}
			}
		}
		return dp[dp.size() - 1];
    }
};

