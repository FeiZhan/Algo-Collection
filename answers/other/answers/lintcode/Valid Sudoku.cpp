class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
		if (0 == board.size() || 0 == board[0].size()) {
			return true;
		}
        for (size_t i = 0; i < board.size(); ++ i) {
			set<int> sudoku;
			for (size_t j = 0; j < board[i].size(); ++ j) {
				if ('.' != board[i][j] && sudoku.end() != sudoku.find(board[i][j])) {
					return false;
				}
				sudoku.insert(board[i][j]);
			}
		}
        for (size_t i = 0; i < board[0].size(); ++ i) {
			set<int> sudoku;
			for (size_t j = 0; j < board.size(); ++ j) {
				if ('.' != board[j][i] && sudoku.end() != sudoku.find(board[j][i])) {
					return false;
				}
				sudoku.insert(board[j][i]);
			}
		}
		for (size_t i = 0; i < board.size(); i += 3) {
			for (size_t j = 0; j < board[i].size(); j += 3) {
				set<int> sudoku;
				for (size_t m = 0; m < board.size() / 3 && i + m < board.size(); ++ m) {
					for (size_t n = 0; n < board[i + m].size() / 3 && j + n < board[i + m].size(); ++ n) {
						if ('.' != board[i + m][j + n] && sudoku.end() != sudoku.find(board[i + m][j + n])) {
							return false;
						}
						sudoku.insert(board[i + m][j + n]);
					}
				}
			}
		}
		return true;
    }
};
