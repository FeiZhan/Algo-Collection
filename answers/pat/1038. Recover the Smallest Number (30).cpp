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
#include <set>
#include <vector>
#include <algorithm>
bool compare(const std::string &x, const std::string &y)
{
	// simple and straightforward
	return x + y < y + x;
	// same
	if (x.length() == y.length())
	{
		return x < y;
	}
	bool flag = true;
	for (size_t i = 0; i < x.length() && i < y.length(); ++ i)
	{
		if (x[i] != y[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		return x + y < y + x;
	} else
	{
		return x < y;
	}
}

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

	int data_num;
	std::cin >> data_num;
	std::string data;
	std::vector<std::string> data_list;
	for (int i = 0; i < data_num; ++ i)
	{
		std::cin >> data;
		data_list.push_back(data);
	}
	std::sort(data_list.begin(), data_list.end(), compare);
	bool flag = true;
	for (std::vector<std::string>::iterator it = data_list.begin(); it != data_list.end(); ++ it)
	{
		if (flag)
		{
			for (size_t i = 0; i < it->length(); ++ i)
			{
				if (! flag || '0' != (*it)[i])
				{
					flag = false;
					std::cout << (*it)[i];
				}
			}
		} else
		{
			std::cout << *it;
		}
	}
	// very ws
	if (flag)
	{
		std::cout << 0 << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
