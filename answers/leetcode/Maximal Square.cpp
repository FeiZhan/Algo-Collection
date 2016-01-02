//@type Dynamic Programming
//@result 67 / 67 test cases passed. Status: Accepted Runtime: 12 ms Submitted: 1 minute ago You are here! Your runtime beats 32.31% of cpp submissions.
//@todo don't understand

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		if (0 == matrix.size()) {
			return 0;
		}
        vector<vector<int> > dp(matrix.size(), vector<int> (matrix[0].size(), 0));
		int max_size(0);
		for (size_t i = 0; i < matrix.size(); ++ i) {
			for (size_t j = 0; j < matrix[i].size(); ++ j) {
				if ('1' == matrix[i][j]) {
					if (0 == i || 0 == j) {
						dp[i][j] = 1;
					}
					else {
						dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
					}
					if (dp[i][j] > max_size) {
						max_size = dp[i][j];
					}
				}
			}
		}
		return max_size * max_size;
    }
};
