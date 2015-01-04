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

// 2015-1-3
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
