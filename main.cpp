#include "include/acm_headers.h"
#include "include/leetcode_helper.h"
using namespace std;



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








