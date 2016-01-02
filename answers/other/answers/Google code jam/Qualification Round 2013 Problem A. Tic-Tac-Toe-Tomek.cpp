//
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <string>
#include <vector>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int case_num;
	std::cin >> case_num;
	const std::string SYMBOL("XO");
	bool not_completed, find_t, win[2], vertical_flag, diagonal1_flag, diagonal2_flag;
	int t_pos[2];
	std::string line;
	std::vector<std::string> board;
	for (int i = 0; i < case_num; ++ i)
	{
		board.clear();
		not_completed = false;
		find_t = false;
		for (int j = 0; j < 4; ++ j)
		{
			std::cin >> line;
			if (! not_completed && line.find('.') != std::string::npos)
			{
				not_completed = true;
			}
			if (! find_t && line.find('T') != std::string::npos)
			{
				find_t = true;
				t_pos[0] = j;
				t_pos[1] = line.find('T');
			}
			board.push_back(line);
		}
		//std::cin >> line;
		win[0] = win[1] = false;
		for (size_t j = 0; j < SYMBOL.length(); ++ j)
		{
			diagonal1_flag = diagonal2_flag = true;
			board[t_pos[0]][t_pos[1]] = SYMBOL[j];
			std::string sym(4, SYMBOL[j]);
			for (int k = 0; k < 4; ++ k)
			{
				// horizontal
				if (board[k] == sym)
				{
					win[j] = true;
					break;
				}
				// vertical
				vertical_flag = true;
				for (int m = 0; m < 4; ++ m)
				{
					if (board[m][k] != SYMBOL[j])
					{
						vertical_flag = false;
						break;
					}
				}
				if (vertical_flag)
				{
					win[j] = true;
					break;
				}
				// diagonal
				if (diagonal1_flag && board[k][k] != SYMBOL[j])
				{
					diagonal1_flag = false;
				}
				if (diagonal2_flag && board[k][3 - k] != SYMBOL[j])
				{
					diagonal2_flag = false;
				}
			}
			if (diagonal1_flag || diagonal2_flag)
			{
				win[j] = true;
			}
		}
		std::cout << "Case #" << i + 1 << ": ";
		if ((win[0] && win[1]) || (! not_completed && ! win[0] && ! win[1]))
		{
			std::cout << "Draw";
		} else if (win[0])
		{
			std::cout << "X won";
		} else if (win[1])
		{
			std::cout << "O won";
		} else
		{
			std::cout << "Game has not completed ";
		}
		std::cout << std::endl;
	}

	return 0;
}
