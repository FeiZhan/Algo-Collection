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

	int sizex, sizey, count;
	string grid[20];
	while (cin >> sizex >> sizey)
	{
		for (int i = 0; i < sizex; ++ i)
		{
			cin >> grid[i];
		}
		count = 0;
		for (int i = 0; i < sizex; ++ i)
		{
			for (int j = 0; j < sizey; ++ j)
			{
				if (grid[i].at(j) == 'W')
				{
					if ((i > 0 && grid[i-1].at(j) == 'P')
						|| (i < sizex-1 && grid[i+1].at(j) == 'P')
						|| (j > 0 && grid[i].at(j-1) == 'P')
						|| (j < sizey-1 && grid[i].at(j+1) == 'P'))
					{
						++ count;
					}
				}
			}
		}
		cout << count << endl;
	}

	return 0;
}
