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
	for (int i = 0; i < case_num; ++ i)
	{
		int sudoku_size;
		std::cin >> sudoku_size;
		int num;
		std::vector<std::vector<int> > sudoku_mat;
		for (int j = 0; j < sudoku_size * sudoku_size; ++ j)
		{
			std::vector<int> sudoku_vec;
			for (int k = 0; k < sudoku_size * sudoku_size; ++ k)
			{
				std::cin >> num;
				sudoku_vec.push_back(num);
			}
			sudoku_mat.push_back(sudoku_vec);
		}
		std::cout << "Case #" << i + 1 << ": ";
		bool flag = true;
		for (int j = 0; j < sudoku_size * sudoku_size; ++ j)
		{
			std::vector<bool> vertical(sudoku_size * sudoku_size, false), horizontal(sudoku_size * sudoku_size, false);
			for (int k = 0; k < sudoku_size * sudoku_size; ++ k)
			{
				if (sudoku_mat[j][k] > 0 && sudoku_mat[j][k] <= sudoku_size * sudoku_size)
				{
					vertical[ sudoku_mat[j][k] - 1 ] = true;
					horizontal[ sudoku_mat[k][j] - 1 ] = true;
				}
			}
			for (int k = 0; k < sudoku_size * sudoku_size; ++ k)
			{
				if (! vertical[k] || ! horizontal[k])
				{
					flag = false;
					break;
				}
			}
			if (! flag)
			{
				break;
			}
		}
		if (! flag)
		{
			std::cout << "No" << std::endl;
			continue;
		}
		for (int j = 0; j < sudoku_size; ++ j)
		{
			for (int k = 0; k < sudoku_size; ++ k)
			{
				std::vector<bool> sub(sudoku_size * sudoku_size, false);
				for (int m = 0; m < sudoku_size; ++ m)
				{
					for (int n = 0; n < sudoku_size; ++ n)
					{
						if (sudoku_mat[j * sudoku_size + m][k * sudoku_size + n] > 0 && sudoku_mat[j * sudoku_size + m][k * sudoku_size + n] <= sudoku_size * sudoku_size)
						{
							sub[ sudoku_mat[j * sudoku_size + m][k * sudoku_size + n] - 1 ] = true;
						}
					}
				}
				for (int m = 0; m < sudoku_size * sudoku_size; ++ m)
				{
					if (! sub[m])
					{
						flag = false;
						break;
					}
				}
				if (! flag)
				{
					break;
				}
			}
			if (! flag)
			{
				break;
			}
		}
		if (! flag)
		{
			std::cout << "No" << std::endl;
		} else
		{
			std::cout << "Yes" << std::endl;
		}
	}

	return 0;
}
