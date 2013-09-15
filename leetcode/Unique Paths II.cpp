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
