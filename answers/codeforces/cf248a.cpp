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

#define MAX_NUM 10000
int leftcbd[MAX_NUM], rightcbd[MAX_NUM];
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

	int cbd_num, left_count, right_count, change_num;
	while (cin >> cbd_num)
	{
		left_count = right_count = 0;
		for (int i = 0; i < cbd_num; ++ i)
		{
			cin >> leftcbd[i] >> rightcbd[i];
			if (leftcbd[i])
				++ left_count;
			if (rightcbd[i])
				++ right_count;
		}
		change_num = (left_count < cbd_num / 2.0) ? left_count : cbd_num - left_count;
		change_num += (right_count < cbd_num / 2.0) ? right_count : cbd_num - right_count;
		cout << change_num << endl;
	}

	return 0;
}
