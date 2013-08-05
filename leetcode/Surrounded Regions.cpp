// TLE

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	for (int i = 0; i < board.size(); ++ i)
		{
			for (int j = 0; j < board[i].size(); ++ j)
			{
				if ('O' == board[i][j])
				{
					findCoast(i, j, board);
				}
			}
		}
		for (int i = 0; i < board.size(); ++ i)
		{
			for (int j = 0; j < board[i].size(); ++ j)
			{
				if ('O' == board[i][j] || 'b' == board[i][j])
				{
					board[i][j] = 'X';
				} else if ('a' == board[i][j])
				{
					board[i][j] = 'O';
				}
			}
		}
    }
    void findCoast(int x, int y, vector<vector<char> > &board)
    {
		if (0 > x || board.size() - 1 < x || 0 > y || board[x].size() - 1 < y)
		{
			return;
		}
		if (0 == x || board.size() - 1 == x || 0 == y || board[x].size() - 1 == y)
		{
			board[x][y] = 'a';
			return;
		}
		if ('X' == board[x - 1][y] && 'X' == board[x + 1][y] && 'X' == board[x][y - 1] && 'X' == board[x][y + 1])
		{
			board[x][y] = 'X';
			return;
		}
		// if previous blocks are 'a'
		if ('a' == board[x - 1][y] || 'a' == board[x][y - 1])
		{
			board[x][y] = 'a';
			return;
		}
		// just consider right and down, ignoring up and left
		if ('O' == board[x + 1][y])
		{
			findCoast(x + 1, y, board);
		}
		if ('a' == board[x + 1][y])
		{
			board[x][y] = 'a';
		}
		if ('O' == board[x][y + 1])
		{
			findCoast(x, y + 1, board);
		}
		if ('a' == board[x][y + 1])
		{
			board[x][y] = 'a';
		}
		// don't need to set else as 'b'
	}
};
int main(int argc, char *argv[])
{
	//["OXXOX","XOOXO","XOXOX","OXOOO","XXOXO"]
	vector<char> tmp;
	vector<vector<char> > input;
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('X');
	input.push_back(tmp);
	tmp.clear();
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	input.push_back(tmp);
	tmp.clear();
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('X');
	input.push_back(tmp);
	tmp.clear();
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	input.push_back(tmp);
	tmp.clear();
	tmp.push_back('X');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	input.push_back(tmp);
	// ["OOOOXX","OOOOOO","OXOXOO","OXOOXO","OXOXOO","OXOOOO"]
	input.clear();
	tmp.clear();
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('X');
	input.push_back(tmp);
	tmp.clear();
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	input.push_back(tmp);
	tmp.clear();
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('O');
	input.push_back(tmp);
	// "OXOOXO","OXOXOO","OXOOOO"]
	tmp.clear();
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	input.push_back(tmp);
	tmp.clear();
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('O');
	input.push_back(tmp);
	tmp.clear();
	tmp.push_back('O');
	tmp.push_back('X');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	tmp.push_back('O');
	input.push_back(tmp);
	Solution s;
	s.solve(input);
	for (int i = 0; i < input.size(); ++ i)
	{
		for (int j = 0; j < input[i].size(); ++ j)
		{
			std::cout << input[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
