//25B - Phone numbers
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

	int dig_num, end_num;
	char digit[110];
	while (cin >> dig_num)
	{
		for (int i = 0; i < dig_num; ++ i)
		{
			cin >> digit[i];
		}
		if (dig_num % 2)
		{
			end_num = dig_num - 1;
		} else
		{
			end_num = dig_num;
		}
		cout << digit[0] << digit[1];
		for (int i = 2; i < end_num; i += 2)
		{
			cout << "-" << digit[i] << digit[i+1];
		}
		for (int i = end_num; i < dig_num; ++ i)
		{
			cout << digit[i];
		}
		cout << endl;
	}

	return 0;
}

