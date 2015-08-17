//TLE
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
#include <deque>
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

	int N;
	std::cin >> N;
	int tmp;
	std::map<int, int> nums;
	std::deque<int> uniques;
	for (int i = 0; i < N; ++ i)
	{
		//std::cin >> tmp;
		scanf("%d", &tmp);
		if (0 == nums[tmp])
		{
			uniques.push_back(tmp);
			nums[tmp] = 1;
		} else
		{
			++ nums[tmp];
			std::deque<int>::iterator it = std::find(uniques.begin(), uniques.end(), tmp);
			if (uniques.end() != it)
			{
				uniques.erase(it);
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < uniques.size(); ++ i)
	{
		if (1 == nums[uniques[i]])
		{
			std::cout << uniques[i] << std::endl;
			flag = true;
			break;
		}
	}
	if (! flag)
	{
		std::cout << "None" << std::endl;
	}

	return 0;
}
