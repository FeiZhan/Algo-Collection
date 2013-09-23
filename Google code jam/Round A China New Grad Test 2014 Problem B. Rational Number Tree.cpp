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
#include <queue>
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

	std::vector<std::pair<long long, long long> > pair_list;
	std::queue<std::pair<long long, long long> > pair_queue;
	std::pair<long long, long long> p(1, 1);
	pair_queue.push(p);
	pair_list.push_back(p);
	while (! pair_queue.empty() && pair_list.size() < 1048576)
	{
		p = pair_queue.front();
		pair_queue.pop();
		std::pair<long long, long long> tmp(p.first, p.first + p.second);
		pair_list.push_back(tmp);
		pair_queue.push(tmp);
		tmp = std::make_pair(p.first + p.second, p.second);
		pair_list.push_back(tmp);
		pair_queue.push(tmp);
	}
	int case_num;
	std::cin >> case_num;
	for (int i = 0; i < case_num; ++ i)
	{
		int type;
		std::cin >> type;
		long long num0, num1;
		std::vector<std::pair<long long, long long> >::iterator it;
		std::cout << "Case #" << i + 1 << ": ";
		switch (type)
		{
		case 1:
			std::cin >> num0;
			-- num0;
			if (num0 < pair_list.size())
			{
				std::cout << pair_list[num0].first << " " << pair_list[num0].second << std::endl;
			} else
			{
				std::cout << "error0" << std::endl;
			}
			break;
		case 2:
			std::cin >> num0 >> num1;
			p = std::make_pair(num0, num1);
			it = std::find(pair_list.begin(), pair_list.end(), p);
			if (it != pair_list.end())
			{
				std::cout << std::distance(pair_list.begin(), it) + 1 << std::endl;
			} else
			{
				std::cout << "error1" << std::endl;
			}
			break;
		default:
			std::cout << "error3" << std::endl;
			break;
		}
	}

	return 0;
}
