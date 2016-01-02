//@type  Depth-first Search Breadth-first Search Union Find
//@result 45 / 45 test cases passed. Status: Accepted Runtime: 8 ms Submitted: 0 minutes ago

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
		int count(0);
        for (size_t i = 0; i < grid.size(); ++ i) {
			for (size_t j = 0; j < grid[i].size(); ++ j) {
				//cout << "test " << i << " " << j << endl;
				if ('1' == grid[i][j]) {
					++ count;
					dfs(i, j, grid);
				}
			}
		}
		return count;
    }
	void dfs(size_t x, size_t y, vector<vector<char> > &grid) {
		if ('1' == grid[x][y]) {
			grid[x][y] = '0';
			if (x >= 1) {
				dfs(x - 1, y, grid);
			}
			if (x + 1 < grid.size()) {
				dfs(x + 1, y, grid);
			}
			if (y >= 1) {
				dfs(x, y - 1, grid);
			}
			if (y + 1 < grid[x].size()) {
				dfs(x, y + 1, grid);
			}
		}
	}
};

int main() {
	vector<vector<char> > grid;
	vector<char> temp;
	temp.push_back('1');
	temp.push_back('0');
	grid.push_back(temp);
	Solution s;
	cout << s.numIslands(grid) << endl;
	return 0;
}