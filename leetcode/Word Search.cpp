class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if (0 == word.length())
		{
			return true;
		}
		std::vector<std::vector<bool> > used;
		for (int i = 0; i < board.size(); ++ i)
		{
			used.push_back( std::vector<bool>(board[i].size(), false) );
		}
		for (int i = 0; i < board.size(); ++ i)
		{
			for (int j = 0; j < board[i].size(); ++ j)
			{
				if (word[0] != board[i][j])
				{
					continue;
				}
				used[i][j] = true;
				if (exist(board, word, used, 0, i, j))
				{
					return true;
				}
				used[i][j] = false;
			}
		}
		return false;
    }
    bool exist(const std::vector<std::vector<char> > &board, const std::string &word, std::vector<std::vector<bool> > &used, const int pos, const int x, const int y)
    {
		if (word.length() == pos + 1)
		{
			return true;
		}
		if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size())
		{
			return false;
		}
		const char target = word[pos + 1];
		const int DIR[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
		for (int i = 0; i < 4; ++ i)
		{
			int loc[2];
			loc[0] = x + DIR[i][0];
			loc[1] = y + DIR[i][1];
			if (loc[0] < 0 || loc[0] >= board.size() || loc[1] < 0 || loc[1] >= board[x].size())
			{
				continue;
			}
			if (! used[loc[0]][loc[1]] && board[loc[0]][loc[1]] == target)
			{
				used[loc[0]][loc[1]] = true;
				if ( exist(board, word, used, pos + 1, loc[0], loc[1]) )
				{
					return true;
				}
				used[loc[0]][loc[1]] = false;
			}
		}
		return false;
	}
};
