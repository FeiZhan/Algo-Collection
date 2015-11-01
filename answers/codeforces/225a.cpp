//
//#define _FILE_DEBUG_
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

	int dice_num, top, left[110], right[110];
	bool flag;
	while (cin >> dice_num >> top)
	{
		flag = true;
		for (int i = 0; i < dice_num; ++ i)
		{
			cin >> left[i] >> right[i];
			if (left[i] == top || right[i] == top
				|| left[i] == 7-top || right[i] == 7-top)
			{
				flag = false;
			}
		}
		cout << (flag ? "YES" : "NO") << endl;
	}

	return 0;
}

