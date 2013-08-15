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
