// idea from internet
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
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int row, column, num, dom = 0, dom_count = 0;
	std::cin >> row >> column;
	for (int i = 0; i < row * column; ++ i)
	{
		//std::cin >> num;
		scanf("%d", &num);
		-- dom_count;
		if (dom_count < 0)
		{
			dom = num;
			dom_count = 0;
		}
	}
	std::cout << dom << std::endl;

	return 0;
}
