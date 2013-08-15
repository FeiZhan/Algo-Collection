class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i = 0; i < board.size(); ++ i)
        {
			vector<char> b;
			for (int j = 0; j < board[i].size(); ++ j)
			{
				if ('.' != board[i][j])
				{
					b.push_back(board[i][j]);
				}
			}
			if (! validate(b))
			{
				return false;
			}
		}
        for (int i = 0; i < board[0].size(); ++ i)
        {
			vector<char> b;
			for (int j = 0; j < board.size(); ++ j)
			{
				if ('.' != board[j][i])
				{
					b.push_back(board[j][i]);
				}
			}
			if (! validate(b))
			{
				return false;
			}
		}
        for (int i = 0; i < board.size(); i += 3)
        {
			for (int j = 0; j < board[i].size(); j += 3)
			{
				vector<char> b;
				for (int k = 0; k < 3; ++ k)
				{
					for (int m = 0; m < 3; ++ m)
					{
						if ('.' != board[i + k][j + m])
						{
							b.push_back(board[i + k][j + m]);
						}
					}
				}
				if (! validate(b))
				{
					return false;
				}
			}
		}
		return true;
    }
	bool validate(const vector<char> &b)
	{
		for (int i = 0; i < b.size(); ++ i)
		{
			for (int j = i + 1; j < b.size(); ++ j)
			{
				if (b[i] == b[j])
				{
					return false;
				}
			}
		}
		return true;
	}
};
