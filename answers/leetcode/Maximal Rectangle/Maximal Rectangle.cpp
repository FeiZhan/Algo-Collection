class Solution {
public:
	int height[1000][1000];
	int maximalRectangle(vector<vector<char> > &matrix) {
		int maxx = 0;
		int row = matrix.size();
		if (0 == row) {
			return 0;
		}
		int col = matrix[0].size();
		if (0 == col) {
			return 0;
		}
		for (int j = 0; j < col; ++j) {
			for (int i = 0; i < row; ++i) {
				if ('0' == matrix[i][j]) {
					height[i][j] = 0;
				}
				else if (0 == i) {
					height[0][j] = 1;
				}
				else {
					height[i][j] = height[i - 1][j] + 1;
				}
			}
		}
		stack<int> s;
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (s.empty()) {
					s.push(j);
				}
				else {
					while (!s.empty() && height[i][s.top()] > height[i][j]) {
						int ph = s.top();
						s.pop();
						if (!s.empty()) {
							maxx = max(maxx, (j - s.top() - 1) * height[i][ph]);
						}
						else {
							maxx = max(maxx, j * height[i][ph]);
						}
					}
					s.push(j);
				}
			}
			while (!s.empty()) {
				int ph = s.top();
				s.pop();
				if (!s.empty()) {
					maxx = max(maxx, (col - s.top() - 1) * height[i][ph]);
				}
				else {
					maxx = max(maxx, col * height[i][ph]);
				}
			}
		}
		return maxx;
	}
};