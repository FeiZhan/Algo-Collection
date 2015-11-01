class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        // write your code here
		vector<long long> dp(A.size(), 0);
		for (size_t i = 0; i < A.size(); ++ i) {
			dp[i] = max(dp[i], static_cast<long long> (A[i]));
			if (i >= 1) {
				dp[i] = max(dp[i], dp[i - 1]);
			}
			if (i >= 2) {
				dp[i] = max(dp[i], dp[i - 2] + A[i]);
			}
		}
		return dp[dp.size() - 1];
    }
};
