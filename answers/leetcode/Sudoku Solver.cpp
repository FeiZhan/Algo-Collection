#include "include/acm_headers.h"
#include "include/leetcode_helper.h"
using namespace std;

class Solution {
public:
	//typedef vector<string > Board;
	typedef vector<vector<char> > Board;
	void solveSudoku(Board &board) {
		solve(board, 0, 0);
	}
	bool solve(Board &board, size_t row, size_t column) {
		//cout << "solve " << row << " " << column << endl;
		//printBoard(board);
		for (size_t i = row; i < board.size(); ++ i) {
			//@note
			for (size_t j = (i <= row ? column : 0); j < board[i].size(); ++ j) {
				//cout << "check " << i << " " << j << endl;
				if ('.' == board[i][j]) {
					bool num_flag[10] = {false};
					for (size_t k = 0; k < board.size(); ++ k) {
						// avoid dot
						if ('.' != board[k][j])
							num_flag[static_cast<unsigned>(board[k][j] - '0')] = true;
					}
					for (size_t k = 0; k < board[i].size(); ++ k) {
						if ('.' != board[i][k])
							num_flag[static_cast<unsigned>(board[i][k] - '0')] = true;
					}
					for (size_t k = 0; k < board.size() / 3; ++ k) {
						for (size_t m = 0; m < board[i].size() / 3; ++ m) {
							//@note
							if ('.' != board[k + i / 3 * 3][m + j / 3 * 3])
								num_flag[static_cast<unsigned>(board[k + i / 3 * 3][m + j / 3 * 3] - '0')] = true;
						}
					}
					for (size_t k = 1; k < 10; ++ k) {
						if (! num_flag[k]) {
							board[i][j] = static_cast<char>(k + '0');
							//cout << "set " << i << " " << j << ": " << k << endl;
							if (solve(board, i, j + 1)) {
								return true;
							}
							board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
    }
	void printBoard(Board &board) {
		for (size_t i = 0; i < board.size(); ++ i) {
			for (size_t j = 0; j < board[i].size(); ++ j) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}
};

int main() {
	Solution s;
	//["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
	//["519748632","783652419","426139875","357986241","264317598","198524367","975863124","832491756","641275983"]
	Solution::Board board;
	board.push_back(string("..9748..."));
	board.push_back(string("7........"));
	board.push_back(string("426139875"));
	board.push_back(string("357986241"));
	board.push_back(string("264317598"));
	board.push_back(string("198524367"));
	board.push_back(string("975863124"));
	board.push_back(string("832491756"));
	board.push_back(string("641275983"));
	s.solveSudoku(board);
	cout << endl;
	s.printBoard(board);
	//cout << ans << endl;

	return 0;
}








