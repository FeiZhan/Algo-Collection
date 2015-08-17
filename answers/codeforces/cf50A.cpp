//50A - Domino piling
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
	fin.open("./input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("./input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("./output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("./output.txt", "w", stdout);
#endif
#endif

	int sizem, sizen, dom_num;
	while (cin >> sizem >> sizen)
	{
		if (sizem % 2 == 0 || sizen % 2 == 0)
		{
			dom_num = sizem * sizen / 2;
		} else
		{
			dom_num = sizem * sizen / 2;
		}
		cout << dom_num << endl;
	}

	return 0;
}
