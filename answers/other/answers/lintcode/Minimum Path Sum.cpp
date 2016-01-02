class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        // write your code here
		vector<vector<int> > dp(grid.size(), vector<int> (grid[0].size(), INT_MAX));
		for (size_t i = 0; i < grid.size(); ++ i) {
			for (size_t j = 0; j < grid[i].size(); ++ j) {
				dp[i][j] = grid[i][j] + ((i > 0 || j > 0) ? min((i > 0 ? dp[i - 1][j] : INT_MAX), (j > 0 ? dp[i][j - 1] : INT_MAX)) : 0);
			}
		}
		return dp.back().back();
    }
};

