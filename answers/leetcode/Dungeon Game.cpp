class Solution {
public:
	int calculateMinimumHP(vector<vector<int> > &dungeon) {
		size_t m = dungeon.size();
		size_t n = dungeon[0].size();
		int d[m][n] = { 0 };
		d[m - 1][n - 1] = minHP(1 - dungeon[m - 1][n - 1]);
		for (int i = m - 2; i >= 0; --i) {
			d[i][n - 1] = minHP(d[i + 1][n - 1] - dungeon[i][n - 1]);
		}
		for (int j = n - 2; j >= 0; --j) {
			d[m - 1][j] = minHP(d[m - 1][j + 1] - dungeon[m - 1][j]);
		}
		for (int i = m - 2; i >= 0; --i) {
			for (int j = n - 2; j >= 0; --j) {
				d[i][j] = minHP(min(d[i + 1][j], d[i][j + 1]) - dungeon[i][j]);
			}
		}
		return d[0][0];
	}
	int minHP(int x) {
		return x <= 0 ? 1 : x;
	}
};