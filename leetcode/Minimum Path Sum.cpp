class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.size() <= 0)
        {
			return 0;
		}
		vector<vector<int> > min_sum;
		for (int i = 0; i < grid.size(); ++ i)
		{
			min_sum.push_back(vector<int>(grid[i].size()));
		}
		min_sum[0][0] = 0;
        for (int i = 0; i < grid.size() + grid[0].size(); ++ i)
        {
			for (int j = 0; j < grid.size(); ++ j)
			{
				int k = i - j;
				if (k >= grid[0].size() || k < 0)
				{
					continue;
				}
				min_sum[j][k] = (j > 0) ? min_sum[j - 1][k] : INT_MAX;
				if (k > 0 && min_sum[j][k] > min_sum[j][k - 1])
				{
					min_sum[j][k] = min_sum[j][k - 1];
				}
				if (INT_MAX == min_sum[j][k])
				{
					min_sum[j][k] = 0;
				}
				min_sum[j][k] += grid[j][k];
			}
		}
		return min_sum[min_sum.size() - 1][min_sum[0].size() - 1];
    }
};
// 2014-04-22 AC clearer version
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