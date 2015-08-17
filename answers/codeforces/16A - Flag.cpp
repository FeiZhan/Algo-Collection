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
	//cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int row, column;
	char color, last_color = '\0', tmp;
	bool flag;
	cin >> row >> column;
	for (int i = 0; i < row; ++ i)
	{
		cin >> color;
		if (color == last_color)
		{
			flag = false;
			break;
		}
		flag = true;
		for (int j = 1; j < column; ++ j)
		{
			cin >> tmp;
			if (color != tmp)
			{
				flag = false;
			}
		}
		if (! flag)
		{
			break;
		}
		last_color = color;
	}
	std::cout << ( flag ? "YES" : "NO" ) << std::endl;

	return 0;
}
