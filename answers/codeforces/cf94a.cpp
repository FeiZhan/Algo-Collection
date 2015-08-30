//94A	 Restoring Password
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

	string all, num[11];
	while (cin >> all && all.size())
	{
		for (int i = 0; i < 10; ++ i)
		{
			cin >> num[i];
		}
		while (all.size())
		{
			for (int i = 0; i < 10; ++ i)
			{
				//cout << all.substr(0, num[i].size() - 1) << endl;
				if (num[i] == all.substr(0, num[i].size()))
				{
					cout << i;
					all.erase(0, num[i].size());
					break;
				}
			}
		}
		cout << endl;
	}

	return 0;
}
