//228B	 Two Tables
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <limits.h>
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

	int size1x, size1y, size2x, size2y, factor, x, y, max;
	bool table1[55][55], table2[55][55];
	char tmp;
	while (cin >> size1x >> size1y)
	{
		x = y = INT_MAX;
		for (int i = 0; i < size1x; ++ i)
		{
			for (int j = 0; j < size1y; ++ j)
			{
				cin >> tmp;
				table1[i][j] = static_cast<bool>(tmp - '0');
			}
		}
		cin >> size2x >> size2y;
		for (int i = 0; i < size2x; ++ i)
		{
			for (int j = 0; j < size2y; ++ j)
			{
				cin >> tmp;
				table2[i][j] = static_cast<bool>(tmp - '0');
			}
		}
		max = 0;
		for (int x_tmp = -size2x-size1x-1; x_tmp < size2x+size1x; ++ x_tmp)
		{
			for (int y_tmp = -size2y-size1y-1; y_tmp < size2y+size1y; ++ y_tmp)
			{
				factor = 0;
				for (int i = 0; i < size1x; ++ i)
				{
					for (int j = 0; j < size1y; ++ j)
					{
						if (i+x_tmp < size2x && j+y_tmp < size2y
							&& i+x_tmp >= 0 && j+y_tmp  >= 0)
						{
							factor += table1[i][j] * table2[i+x_tmp][j+y_tmp];
						}
					}
				}
				//cout << "x_tmp " << x_tmp << " y_tmp " << y_tmp;
				//cout << " factor " << factor << endl;
				if (max < factor)
				{
					max = factor;
					x = x_tmp;
					y = y_tmp;
				}
			}
		}
		cout << x << " " << y << endl;
	}

	return 0;
}

