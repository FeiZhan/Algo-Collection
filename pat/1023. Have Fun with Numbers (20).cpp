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

#include <string>
#include <vector>
#include <algorithm>

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

	std::string raw, doubled;
	std::cin >> raw;
	doubled = raw;
	int carry = 0;
	for (int i = 0; i < doubled.length(); ++ i)
	{
		int digit = static_cast<int>(doubled[doubled.length() - i - 1] - '0') * 2 + carry;
		doubled[doubled.length() - i - 1] = static_cast<char>(digit % 10 + '0');
		carry = digit / 10;
	}
	while (carry)
	{
		doubled = static_cast<char>(carry % 10 + '0') + doubled;
		carry /= 10;
	}
	bool flag;
	std::string sorted(doubled);
	if (carry)
	{
		flag = false;
	} else
	{
		std::sort(raw.begin(), raw.end());
		std::sort(sorted.begin(), sorted.end());
		//std::cout << "test" << std::endl << raw << " " << doubled << " " << sorted << std::endl;
		flag = raw == sorted;
	}
	if (flag)
	{
		std::cout << "Yes" << std::endl << doubled << std::endl;
	} else
	{
		std::cout << "No" << std::endl << doubled << std::endl;
	}

	return 0;
}
