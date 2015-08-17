class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		if (0 == n)
		{
			return ans;
		}
		std::vector<std::string> board(n, string(n, '.'));
		solveNQueens(board, 0);
		return this->ans;
	}
	void solveNQueens(const std::vector<std::string> &board, int row)
	{
		if (board.size() == row)
		{
			this->ans.push_back(board);
			return;
		}
		for (size_t i = 0; i < board[0].length(); ++i)
		{
			bool flag = true;
			for (size_t j = 0; j < board.size(); ++j)
			{
				if ('Q' == board[j][i])
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				continue;
			}
			for (size_t j = 0; j < board.size(); ++j)
			{
				if (i - row + j >= 0 && i - row + j < board[0].length() && 'Q' == board[j][i - row + j])
				{
					flag = false;
					break;
				}
			}
			if (!flag)
			{
				continue;
			}
			for (size_t j = 0; j < board.size(); ++j)
			{
				if (i + row - j >= 0 && i + row - j < board[0].length() && 'Q' == board[j][i + row - j])
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				std::vector<std::string> temp(board);
				temp[row][i] = 'Q';
				solveNQueens(temp, row + 1);
			}
		}
	}
	void output(void)
	{
		for (size_t i = 0; i < this->ans.size(); ++i)
		{
			if (i > 0)
			{
				std::cout << ",";
			}
			std::cout << "[";
			for (size_t j = 0; j < this->ans[i].size(); ++j)
			{
				std::cout << "[" << this->ans[i][j] << "]";
			}
			std::cout << "]";
		}
	}
	vector<vector<string> > ans;
};