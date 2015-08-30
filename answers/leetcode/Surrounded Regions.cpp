class Solution {
public:
    void solve(vector<vector<char>> &board) {
		for (size_t i = 0; i < board.size(); ++ i) {
			for (size_t j = 0; j < board[i].size(); ++ j) {
				if ('x' == board[i][j] || 'X' == board[i][j] || '1' == board[i][j]) {
					continue;
				}
				if (0 == i || board.size() - 1 == i || 0 == j || board[i].size() - 1 == j) {
					board[i][j] = '1';
				}
				else if ('1' == board[i - 1][j] || '1' == board[i + 1][j] || '1' == board[i][j - 1] || '1' == board[i][j + 1]) {
					board[i][j] = '1';
				}
			}
		}
		for (size_t i = 0; i < board.size(); ++ i) {
			for (size_t j = 0; j < board[i].size(); ++ j) {
				size_t x = board.size() - i - 1;
				size_t y = board[i].size() - j - 1;
				if ('x' == board[x][y] || 'X' == board[x][y] || '1' == board[x][y]) {
					continue;
				}
				if (0 == x || board.size() - 1 == x || 0 == y || board[x].size() - 1 == y) {
					board[x][y] = '1';
				}
				else if ('1' == board[x - 1][y] || '1' == board[x + 1][y] || '1' == board[x][y - 1] || '1' == board[x][y + 1]) {
					board[x][y] = '1';
				}
			}
		}
		for (size_t i = 0; i < board.size(); ++ i) {
			for (size_t j = 0; j < board[i].size(); ++ j) {
				if ('x' == board[i][j] || 'X' == board[i][j] || '1' == board[i][j]) {
					continue;
				}
				if (0 == i || board.size() - 1 == i || 0 == j || board[i].size() - 1 == j) {
					dfs(i, j, board);
				}
				else if ('1' == board[i - 1][j] || '1' == board[i + 1][j] || '1' == board[i][j - 1] || '1' == board[i][j + 1]) {
					dfs(i, j, board);
				}
			}
		}
		for (size_t i = 0; i < board.size(); ++ i) {
			for (size_t j = 0; j < board[i].size(); ++ j) {
				if ('O' == board[i][j]) {
					board[i][j] = 'X';
				}
				else if ('1' == board[i][j]) {
					board[i][j] = 'O';
				}
			}
		}
    }
	void dfs(size_t x, size_t y, vector<vector<char> > &board) {
		if (0 == x || board.size() - 1 == x || 0 == y || board[x].size() - 1 == y) {
			return;
		}
		if ('x' == board[x][y] || 'X' == board[x][y] || '1' == board[x][y]) {
			return;
		}
		board[x][y] = '1';
		dfs(x - 1, y, board);
		dfs(x + 1, y, board);
		dfs(x, y - 1, board);
		dfs(x, y + 1, board);
	}
};
