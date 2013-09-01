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

#include <vector>

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

	long long num, base;
	std::cin >> num >> base;
	std::vector<int> digits;
	while (num > 0)
	{
		digits.push_back(num % base);
		num /= base;
	}
	if (digits.size() == 0)
	{
		digits.push_back(0);
	}
	bool flag = true;
	for (size_t i = 0; i < digits.size() / 2; ++ i)
	{
		if (digits[i] != digits[digits.size() - 1 - i])
		{
			flag = false;
			break;
		}
	}
	std::cout << (flag ? "Yes" : "No") << std::endl;
	for (int i = digits.size() - 1; i >= 0; -- i)
	{
		std::cout << digits[i];
		if (i > 0)
		{
			std::cout << " ";
		}
	}

	return 0;
}
