//192A - Funky Numbers
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <cmath>
#include <set>
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

	int num, tmp;
	set<int> tri, tri_sum;
	bool flag;
	while (cin >> num)
	{
		tri.clear();
		tri_sum.clear();
		flag = false;
		for (int i = 1; i * (i+1) < num * 2; ++ i)
		{
			//tri.insert(i * (i+1) / 2);
			//for (set<int>::iterator it = tri.begin(); it != tri.end(); ++ it)
			//{
			//	tri_sum.insert(*it + i * (i+1) / 2);
			//}
			tmp = sqrt((num - i * (i+1) / 2) * 2);
			if (i * (i+1) / 2 + tmp * (tmp+1) / 2 == num)
			{
				cout << "YES" << endl;
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			cout << "NO" << endl;
		}
		//if (tri_sum.find(num) != tri_sum.end())
		//{
		//	cout << "YES";
		//} else
		//{
		//	cout << "NO";
		//}
		//cout << endl;
	}

	return 0;
}

