// 2015-1-3
//@result 501 / 501 test cases passed. Status: Accepted Runtime: 20 ms Submitted: 0 minutes ago You are here! Your runtime beats 24.26% of cpp submissions.

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		for (size_t i = 0; i < board.size(); ++ i) {
			if (! isValid(board[i])) {
				return false;
			}
		}
		if (board.size() > 0) {
			for (size_t i = 0; i < board[0].size(); ++ i) {
				vector<char> temp;
				for (size_t j = 0; j < board.size(); ++ j) {
					temp.push_back(board[j][i]);
				}
				if (! isValid(temp)) {
					return false;
				}
			}
		}
		for (size_t i = 0; i < 3; ++ i) {
			for (size_t j = 0; j < 3; ++ j) {
				vector<char> temp;
				for (size_t k = 0; k < board.size() / 3; ++ k) {
					for (size_t m = 0; m < board[0].size() / 3; ++ m) {
						temp.push_back(board[i * (board.size() / 3) + k][j * (board[0].size() / 3) + m]);
					}
				}
				if (! isValid(temp)) {
					return false;
				}
			}
		}
		return true;
	}
	bool isValid(const vector<char> &line) {
		//cout << endl;
		for (size_t i = 0; i < line.size(); ++ i) {
			//cout << line[i];
			if ('.' == line[i]) {
				continue;
			}
			for (size_t j = i + 1; j < line.size(); ++ j) {
				if (line[i] == line[j]) {
					return false;
				}
			}
		}
		return true;
	}
};
