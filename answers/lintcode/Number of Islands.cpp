class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        // Write your code here
		if (0 == grid.size() || 0 == grid[0].size()) {
			return 0;
		}
		vector<vector<bool> > flag(grid.size(), vector<bool> (grid[0].size(), false));
		int count(0);
		for (size_t i = 0; i < grid.size(); ++ i) {
			for (size_t j = 0; j < grid[i].size(); ++ j) {
				if (grid[i][j] && ! flag[i][j]) {
					dfs(i, j, grid, flag);
					++ count;
				}
			}
		}
		return count;
    }
	void dfs(size_t x, size_t y, const vector<vector<bool> > &grid, vector<vector<bool> > &flag) {
		if (x >= grid.size() || y >= grid[x].size() || ! grid[x][y] || flag[x][y]) {
			return;
		}
		flag[x][y] = true;
		dfs(x - 1, y, grid, flag);
		dfs(x + 1, y, grid, flag);
		dfs(x, y - 1, grid, flag);
		dfs(x, y + 1, grid, flag);
	}
};
