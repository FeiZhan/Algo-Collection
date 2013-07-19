//A. Dress'em in Vests!
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
#include <map>
#include <algorithm>
#define MAX_NUM 110000
int sold[MAX_NUM], vest[MAX_NUM];
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

	int sold_num, vest_num, low, high, begin;
	map<int, int> sold_map;
	while (cin >> sold_num >> vest_num >> low >> high)
	{
		for (int i = 0; i < sold_num; ++ i)
		{
			cin >> sold[i];
		}
		sort(sold, sold + sold_num);
		sold_map.clear();
		for (int i = 0; i < vest_num; ++ i)
		{
			cin >> vest[i];
		}
		sort(vest, vest + vest_num);
		begin = 0;
		for (int i = 0; i < vest_num; ++ i)
		{
			for (int j = begin; j < sold_num; ++ j)
			{
				//cout << "iteration " << i << " " << j << endl;
				if (vest[i] >= sold[j] - low && vest[i] <= sold[j] + high)
				{
					sold_map.insert(make_pair(j, i));
					begin = j + 1;
					break;
				}
				else if (vest[i] < sold[j] - low)
				{
					break;
				} else // important, or exceed time limit
				{
					begin = j + 1;
				}
			}
		}
		cout << sold_map.size() << endl;
		for (map<int, int>::iterator it = sold_map.begin();
			it != sold_map.end(); ++ it)
		{
			cout << it->first + 1 << " " << it->second + 1 << endl;
		}
	}

	return 0;
}
