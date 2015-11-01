//102B	 Sum of Digits
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <memory.h>
#include <string>
#define MAX_NUM 101000
int big_int[MAX_NUM], tmp[MAX_NUM];
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

	string num;
	int count, size, tmp_size;
	while (cin >> num && num.size())
	{
		count = 0;
		memset(big_int, 0, sizeof(big_int));
		for (int i = 0; i < num.size(); ++ i)
		{
			big_int[i] += static_cast<int>(num.at(i) - '0');
		}
		size = num.size();
		while (size > 1)
		{
			memset(tmp, 0, sizeof(tmp));
			tmp_size = 1;
			for (int i = 0; i < size; ++ i)
			{
				tmp[0] += big_int[i];
				//cout << "tmp ";
				//for (int j = 0; j < tmp_size; ++ j)
				//{
				//	cout << tmp[j];
				//}
				//cout << " size " << tmp_size << endl;
				for (int j = 0; j < tmp_size; ++ j)
				{
					if (tmp[j] >= 10)
					{
						tmp[j + 1] += tmp[j] / 10;
						tmp[j] %= 10;
						if (tmp_size < j + 2)
						{
							tmp_size = j + 2;
						}
					} else
					{
						break;
					}
				}
			}
			for (int i = 0; i < tmp_size; ++ i)
			{
				big_int[i] = tmp[i];
			}
			for (int i = tmp_size; i < size; ++ i)
			{
				big_int[i] = 0;
			}
			size = tmp_size;
			++ count;
		}
		cout << count << endl;
	}

	return 0;
}

