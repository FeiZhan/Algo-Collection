// 2014-04-22 AC clearer version
//@result 61 / 61 test cases passed. Status: Accepted Runtime: 32 ms Submitted: 1 minute ago You are here! Your runtime beats 11.17% of cpp submissions.

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (0 == grid.size())
		{
			return 0;
		}
		vector<vector<int> > path(grid.size(), vector<int>(grid[0].size(), INT_MAX));
		for (size_t i = 0; i < grid.size(); ++i)
		{
			for (size_t j = 0; j < grid[i].size(); ++j)
			{
				if (i > 0 && path[i - 1][j] + grid[i][j] < path[i][j])
				{
					path[i][j] = path[i - 1][j] + grid[i][j];
				}
				if (j > 0 && path[i][j - 1] + grid[i][j] < path[i][j])
				{
					path[i][j] = path[i][j - 1] + grid[i][j];
				}
				if (INT_MAX == path[i][j])
				{
					path[i][j] = grid[i][j];
				}
			}
		}
		return path.back().back();
	}
};
