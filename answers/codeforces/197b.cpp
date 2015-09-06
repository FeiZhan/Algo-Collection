//197B - Limit
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
int gcd(int m, int n)
{
	int tmp;
	if (m < n)
	{
		tmp = m;
		m = n;
		n = tmp;
	}
	if (m % n == 0)
	{
		return n;
	} else
	{
		return gcd(n, m % n);
	}
}
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

	int size1, size2, poly1[110], poly2[110];
	while (cin >> size1 >> size2)
	{
		for (int i = 0; i < size1 + 1; ++ i)
		{
			cin >> poly1[i];
		}
		for (int i = 0; i < size2 + 1; ++ i)
		{
			cin >> poly2[i];
		}
		if (size1 > size2)
		{
			if (poly1[0] * poly2[0] < 0)
			{
				cout << "-";
			}
			cout << "Infinity" << endl;
		}
		else if (size1 < size2)
		{
			cout << "0/1" << endl;
		} else
		{
			if (poly1[0] * poly2[0] < 0)
			{
				cout << "-";
			}
			poly1[0] = abs(poly1[0]);
			poly2[0] = abs(poly2[0]);
			int _gcd = gcd(poly1[0], poly2[0]);
			cout << poly1[0] / _gcd << "/" << poly2[0] / _gcd << endl;
		}
	}

	return 0;
}

