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

	std::string num;
	long long sum = 0;
	cin >> num;
	for (size_t i = 0; i < num.length(); ++ i)
	{
		sum += static_cast<long long> (num[i] - '0');
	}
	std::vector<int> sum_vec;
	while (sum > 0)
	{
		sum_vec.push_back(sum % 10);
		sum /= 10;
	}
	if (0 == sum_vec.size())
	{
		sum_vec.push_back(0);
	}
	const std::string WORDS[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for (int i = sum_vec.size() - 1; i >= 0; -- i)
	{
		cout << WORDS[sum_vec[i]];
		if (i > 0)
		{
			std::cout << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}
