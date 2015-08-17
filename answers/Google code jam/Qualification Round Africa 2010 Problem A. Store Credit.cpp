// AC for small and large

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

	int case_num;
	std::cin >> case_num;
	int credit, item_num, item;
	std::vector<int> item_list;
	for (int i = 0; i < case_num; ++ i)
	{
		std::cin >> credit >> item_num;
		std::cout << "Case #" << i + 1 << ": ";
		item_list.clear();
		for (int j = 0; j < item_num; ++ j)
		{
			std::cin >> item;
			for (size_t k = 0; k < item_list.size(); ++ k)
			{
				if (item + item_list[k] == credit)
				{
					std::cout << k + 1 << " " << j + 1;
				}
			}
			item_list.push_back(item);
		}
		std::cout << std::endl;
	}

	return 0;
}
