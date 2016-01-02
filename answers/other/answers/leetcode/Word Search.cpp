class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		this->board = board;
		this->word = word;
		for (size_t i = 0; i < board.size(); ++ i) {
			for (size_t j = 0; j < board[i].size(); ++ j) {
				if (board[i][j] == word[0] && exist(i, j, 0)) {
					return true;
				}
			}
		}
		return false;
    }
    bool exist(size_t row, size_t column, size_t pos) {
		if (pos + 1 >= word.length()) {
			return true;
		}
		char temp = board[row][column];
		board[row][column] = '-';
		if (row > 0 && board[row - 1][column] == word[pos + 1] && exist(row - 1, column, pos + 1)) {
			return true;
		}
		if (row + 1 < board.size() && board[row + 1][column] == word[pos + 1] && exist(row + 1, column, pos + 1)) {
			return true;
		}
		if (column > 0 && board[row][column - 1] == word[pos + 1] && exist(row, column - 1, pos + 1)) {
			return true;
		}
		if (column + 1 < board[row].size() && board[row][column + 1] == word[pos + 1] && exist(row, column + 1, pos + 1)) {
			return true;
		}
		board[row][column] = temp;
		return false;
	}
	vector<vector<char> > board;
	string word;
};
