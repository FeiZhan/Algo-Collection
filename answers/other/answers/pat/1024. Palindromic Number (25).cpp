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

	std::string num, tmp;
	int step, carry;
	bool flag = false;
	std::cin >> num >> step;
	for (int i = 0; i < step; ++ i)
	{
		flag = true;
		for (size_t j = 0; j < num.length() / 2; ++ j)
		{
			if (num[j] != num[num.length() - 1 - j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			std::cout << num << std::endl << i << std::endl;
			break;
		}
		tmp = num;
		carry = 0;
		for (size_t j = 0; j < tmp.length(); ++ j)
		{
			num[tmp.length() - 1 - j] += tmp[j] - '0' + carry;
			carry = static_cast<int>(num[tmp.length() - 1 - j] - '0') / 10;
			num[tmp.length() - 1 - j] = (num[tmp.length() - 1 - j] - '0') % 10 + '0';
		}
		while (carry)
		{
			num.insert(num.begin(), static_cast<char>(carry % 10 + '0'));
			carry /= 10;
		}
	}
	if (! flag)
	{
		std::cout << num << std::endl << step << std::endl;
	}
	return 0;
}
