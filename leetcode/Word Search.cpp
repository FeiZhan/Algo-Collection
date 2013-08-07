// doing
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<int> usedx, usedy;
		for (int i = 0; i < board.size(); ++ i)
		{
			for (int j = 0; j < board[i].size(); ++ j)
			{
				if (word[0] == board[i][j] && existRec(board, word, i, j, usedx, usedy))
				{
					return true;
				}
			}
		}
		return false;
    }
    bool existRec(const vector<vector<char> > &board, const string &word, const int x, const int y, const vector<int> &usedx, const vector<int> &usedy)
    {
		for (int i = -1; i <= 1; i += 2)
		{
			if ()
		}
	}
};
