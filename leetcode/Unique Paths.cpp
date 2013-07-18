class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > path;
        for (int i = 0; i < m; ++ i)
        {
			vector<int> tmp;
			for (int j = 0; j < n; ++ j)
			{
				tmp.push_back(0);
			}
			path.push_back(tmp);
		}
		for (int i = m - 1; i >= 0; -- i)
		{
			for (int j = n - 1; j >= 0; -- j)
			{
				// set the first node as 1 path
				if (i == m - 1 && j == n - 1)
				{
					path[i][j] = 1;
					continue;
				}
				if (i != m - 1)
				{
					path[i][j] += path[i + 1][j];
				}
				if (j != n - 1)
				{
					path[i][j] += path[i][j + 1];
				}
			}
		}
		return path[0][0];
    }
};
