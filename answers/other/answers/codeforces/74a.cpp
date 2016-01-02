//74A	 Room Leader
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

	int con_num, score[55], hack1, hack2, tmp, max = -INT_MAX, max_con;
	string name[55];
	cin >> con_num;
	for (int i = 0; i < con_num; ++ i)
	{
		cin >> name[i] >> hack1 >> hack2;
		score[i] = 100 * hack1 - 50 * hack2;
		for (int j = 0; j < 5; ++ j)
		{
			cin >> tmp;
			score[i] += tmp;
		}
		if (max < score[i])
		{
			max = score[i];
			max_con = i;
		}
	}
	cout << name[max_con] << endl;

	return 0;
}
