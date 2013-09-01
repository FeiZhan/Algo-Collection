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

	std::string color[3], color13("#"), color_tmp;
	int num, tmp;
	char digit;
	for (int i = 0; i < 3; ++ i)
	{
		std::cin >> color[i];
		num = 0;
		for (size_t j = 0; j < color[i].length(); ++ j)
		{
			digit = color[i][j];
			tmp = static_cast<int> ( digit >= '0' && digit <= '9' ? digit - '0' : digit - 'A' + 10 );
			num = num * 10 + tmp;
		}
		color_tmp.clear();
		while (num > 0)
		{
			tmp = num % 13;
			digit = static_cast<char> (tmp < 10 ? tmp + '0' : tmp - 10 + 'A');
			color_tmp.push_back(digit);
			num /= 13;
		}
		while (color_tmp.size() < 2)
		{
			color_tmp.push_back('0');
		}
		color13 += std::string( color_tmp.rbegin(), color_tmp.rend() );
	}
	std::cout << color13 << std::endl;

	return 0;
}
