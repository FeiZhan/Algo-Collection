//@result 61 / 61 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago You are here! Your runtime beats 7.70% of cpp submissions.

class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		// initialize a m * n matrix
        vector<vector<int> > path(m, std::vector<int>(n));
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
