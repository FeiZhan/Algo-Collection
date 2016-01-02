//158B  Taxi
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;
#include <set>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf()); // assign file's streambuf to cin
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf()); // assign file's streambuf to cout
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int grp_sum, taxi_sum, tmp, cnt1;
	multiset<int> group;
	multiset<int>::iterator it;
	while (cin >> grp_sum)
	{
		taxi_sum = 0;
		group.clear();
		for (int i = 0; i < grp_sum; ++ i)
		{
			cin >> tmp;
			if (tmp == 4)
			{
				taxi_sum ++;
			}
			else
			{
				it = group.find(4 - tmp);
				if (it == group.end())
				{
					group.insert(tmp);
				}
				else
				{
					group.erase(it);
					taxi_sum ++;
				}
			}
		}
		cnt1 = group.count(1);
		if ((it = group.find(2)) != group.end() && cnt1 > 0)
		{
			group.erase(it);
			for (int i = 0; i < 2 && i < cnt1; ++ i)
			{
				group.erase(group.begin());
			}
			cnt1 -= 2;
			taxi_sum ++;
		}
		if (cnt1 >= 4)
		{
			for (int i = 0; i < cnt1 / 4 * 4; ++ i)
			{
				group.erase(group.begin());
			}
			taxi_sum += cnt1 / 4;
			cnt1 %= 4;
		}
		if (cnt1 > 0)
		{
			for (int i = 0; i < cnt1; ++ i)
			{
				group.erase(group.begin());
			}
			taxi_sum ++;
		}
		cout << taxi_sum + group.size() << endl;
	}

	return 0;
}