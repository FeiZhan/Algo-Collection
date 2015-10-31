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
				if (sudoku.end() != sudoku.find(board[i][j])) {
					return false;
				}
				sudoku.insert(board[i][j]);
			}
		}
        for (size_t i = 0; i < board[0].size(); ++ i) {
			set<int> sudoku;
			for (size_t j = 0; j < board.size(); ++ j) {
				if (sudoku.end() != sudoku.find(board[j][i])) {
					return false;
				}
				sudoku.insert(board[j][i]);
			}
		}
    }
};
