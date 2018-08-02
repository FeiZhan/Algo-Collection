//@type Array
//@result 22 / 22 test cases passed. Status: Accepted Runtime: 0 ms Submitted: 0 minutes ago

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		if (0 == board.size()) {
			return;
		}
		vector<vector<int> > count_mat(board.size(), vector<int> (board[0].size(), 0));
        for (size_t i = 0; i < board.size(); ++ i) {
			for (size_t j = 0; j < board[i].size(); ++ j) {
				if (1 == board[i][j]) {
					for (int k = -1; k <= 1; ++ k) {
						for (int m = -1; m <= 1; ++ m) {
							if (i + k >= 0 && i + k < board.size() && j + m >= 0 && j + m < board[i + k].size() && (k | m)) {
								++ count_mat[i + k][j + m];
							}
						}
					}
				}
			}
		}
        for (size_t i = 0; i < count_mat.size(); ++ i) {
			for (size_t j = 0; j < count_mat[i].size(); ++ j) {
				if (count_mat[i][j] < 2 || count_mat[i][j] > 3) {
					board[i][j] = 0;
				}
				if (3 == count_mat[i][j]) {
					board[i][j] = 1;
				}
			}
		}
    }
};