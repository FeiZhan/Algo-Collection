class Solution {
public:
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    vector<vector<string> > solveNQueens(int n) {
        // write your code here
		nqueens_list.clear();
		vector<string> nqueens(n, string(n, '.'));
		solveNQueens(nqueens, 0);
		return nqueens_list;
    }
	void solveNQueens(vector<string> &nqueens, int i) {
		if (i >= nqueens.size()) {
			nqueens_list.push_back(nqueens);
			return;
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
					solveNQueens(nqueens, i + 1);
					nqueens[i][j] = '.';
				}
			}
		}
	}
	vector<vector<string> > nqueens_list;
};

