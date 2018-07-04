// 1D dp, copied from leetcode

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int m = obstacleGrid.size(), n = obstacleGrid[0].size();
		std::vector<int> dp(n + 1, 0);
		int i = n - 1;
		-- m;
		while (i >= 0 && obstacleGrid[m][i] == 0)
		{
			dp[i --] = 1;
		}
		while (m -- > 0)
		{
			for (i = n - 1; i >= 0; -- i)
			{
				dp[i] = (1 == obstacleGrid[m][i]) ? 0 : dp[i] + dp[i + 1];
			}
		}
		return dp[0];
    }
};

// 2015-01-10
// 2d dp, 1d dp is rolling array
//@result 43 / 43 test cases passed. Status: Accepted Runtime: 4 ms Submitted: 0 minutes ago You are here! Your runtime beats 13.67% of cpp submissions.

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (0 == obstacleGrid.size() || 0 == obstacleGrid[0].size()) {
			return 0;
		}
		vector<vector<int> > dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
		for (size_t i = 0; i < obstacleGrid.size(); ++i) {
			dp[i][0] = obstacleGrid[i][0] ? 0 : (i ? dp[i - 1][0] : 1);
			for (size_t j = 1; j < obstacleGrid[i].size(); ++j) {
				dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i][j - 1] + (i ? dp[i - 1][j] : 0);
			}
		}
		return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
	}
};
