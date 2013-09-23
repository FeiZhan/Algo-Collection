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

	int case_num;
	std::cin >> case_num;
	for (int i = 0; i < case_num; ++ i)
	{
		int book_num;
		std::cin >> book_num;
		int book;
		std::vector<int> book_list, odd_list, even_list;
		for (int j = 0; j < book_num; ++ j)
		{
			std::cin >> book;
			book_list.push_back(book);
			if (book % 2)
			{
				odd_list.push_back(book);
			} else
			{
				even_list.push_back(book);
			}
		}
		std::sort(odd_list.begin(), odd_list.end());
		std::sort(even_list.begin(), even_list.end(), std::greater<int>());
		std::cout << "Case #" << i + 1 << ":";
		for (int j = 0, k = 0, m = 0; j < book_list.size(); ++ j)
		{
			if (book_list[j] % 2)
			{
				if (odd_list.size() > k)
				{
					std::cout << " " << odd_list[k];
					++ k;
				} else
				{
					std::cout << " odd_list ";
				}
			} else
			{
				if (even_list.size() > m)
				{
					std::cout << " " << even_list[m];
					++ m;
				} else
				{
					std::cout << " even_list ";
				}
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
