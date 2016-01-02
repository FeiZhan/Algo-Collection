//
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <map>
#include <iomanip>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("../input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("../input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("../output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int len1, len2, exp;
	double coef;
	std::map<int, double> poly1, poly2;
	std::cin >> len1;
	for (int i = 0; i < len1; ++ i)
	{
		cin >> exp >> coef;
		poly1.insert(std::make_pair(exp, coef));
	}
	std::cin >> len2;
	for (int i = 0; i < len2; ++ i)
	{
		cin >> exp >> coef;
		poly2.insert(std::make_pair(exp, coef));
	}
	for (std::map<int, double>::iterator it = poly2.begin(); it != poly2.end(); ++ it)
	{
		if (0 == poly1[it->first])
		{
			poly1[it->first] = it->second;
		} else
		{
			poly1[it->first] += it->second;
		}
	}
	for (std::map<int, double>::iterator it = poly1.begin(); it != poly1.end(); ++ it)
	{
		if (0.0 == it->second)
		{
			poly1.erase(it);
		}
	}
	std::cout << poly1.size();
	for (std::map<int, double>::reverse_iterator it = poly1.rbegin(); it != poly1.rend(); ++ it)
	{
		//std::cout << " " << it->first << " " << setprecision(2) << it->second;
		printf(" %d %.1lf", it->first, it->second);
	}
	std::cout << std::endl;
	return 0;
}
