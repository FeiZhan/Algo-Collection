class Solution {
public:
    /**
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        // write your code here
		vector<vector<int> > dp(A.size(), vector<int> (101, INT_MAX));
		for (size_t i = 0; i < dp.size(); ++ i) {
			for (size_t j = 0; j < dp[i].size(); ++ j) {
				for (size_t k = max(0, int(j) - target); k <= min(int(j) + target, int(dp[i].size()) - 1); ++ k) {
					dp[i][j] = min(dp[i][j], (i > 0 ? dp[i - 1][k] : 0) + abs(A[i] - int(j)));
				}
			}
		}
		int min_adj(INT_MAX);
		for (size_t i = 0; i < dp[A.size() - 1].size(); ++ i) {
			min_adj = min(min_adj, dp[A.size() - 1][i]);
		}
		return min_adj;
    }
};
