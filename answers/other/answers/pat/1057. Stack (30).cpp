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
#include <stack>
#include <set>
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

	int action_num;
	std::cin >> action_num;
	std::stack<int> s;
	std::multiset<int> stack_set;
	std::multiset<int>::iterator it, median = stack_set.begin();
	for (int i = 0; i < action_num; ++ i)
	{
		std::string action;
		int num;
		std::cin >> action;
		switch (action[1])
		{
		case 'u':
			std::cin >> num;
			s.push(num);
			stack_set.insert(num);
			if (num >= *median && stack_set.size() % 2)
			{
				++ median;
			} else if (num < *median && stack_set.size() % 2 == 0 && median != stack_set.begin())
			{
				-- median;
			}
			break;
		case 'o':
			if (s.empty())
			{
				std::cout << "Invalid" << std::endl;
			} else
			{
				num = s.top();
				std::cout << num << std::endl;
				it = stack_set.lower_bound(num);
				stack_set.erase(it);
				if (num >= *median && stack_set.size() % 2 && median != stack_set.begin())
				{
					-- median;
				} else if (num < *median && stack_set.size() % 2 == 0 && median != stack_set.end())
				{
					++ median;
				}
				s.pop();
			}
			break;
		case 'e':
			if (s.empty())
			{
				std::cout << "Invalid" << std::endl;
			} else
			{
				std::multiset<int>::iterator it2 = stack_set.begin();
				for (size_t i = 0; i < stack_set.size() / 2; ++ i)
				{
					++ it2;
				}
				if (stack_set.size() % 2 == 0)
				{
					++ it2;
				}
				median = it2;
				std::cout << *median << std::endl;
				//std::cout << "test " << stack_set.size() << " " << std::distance(stack_set.begin(), median) << std::endl;
			}
			break;
		}
	}

	return 0;
}
