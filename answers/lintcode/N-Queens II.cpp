class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    int totalNQueens(int n) {
        // write your code here
		vector<string> nqueens(n, string(n, '.'));
		return solveNQueens(nqueens, 0);
    }
	int solveNQueens(vector<string> &nqueens, int i) {
		int count = 0;
		if (i >= nqueens.size()) {
			return 1;
		}
		for (size_t j = 0; j < nqueens[i].size(); ++ j) {
			if ('.' == nqueens[i][j]) {
				bool flag = true;
				for (size_t k = 0; k < nqueens.size(); ++ k) {
					if ('Q' == nqueens[k][j]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (size_t m = i - 1, n = j - 1; m < nqueens.size() && n < nqueens[m].size(); -- m, -- n) {
						if ('Q' == nqueens[m][n]) {
							flag = false;
							break;
						}
					}
				}
				if (flag) {
					for (size_t m = i - 1, n = j + 1; m < nqueens.size() && n < nqueens[m].size(); -- m, ++ n) {
						if ('Q' == nqueens[m][n]) {
							flag = false;
							break;
						}
					}
				}
				if (flag) {
					nqueens[i][j] = 'Q';
					count += solveNQueens(nqueens, i + 1);
					nqueens[i][j] = '.';
				}
			}
		}
		return count;
	}
};

