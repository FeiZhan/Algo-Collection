//@result TLE

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
		vector<int> dp(A.size(), INT_MAX);
		dp[0] = 0;
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 1; j <= A[i] && i + j < dp.size(); ++ j) {
				dp[i + j] = min(dp[i + j], dp[i] + 1);
			}
		}
		return dp[dp.size() - 1];
    }
};
