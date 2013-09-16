// AC for small

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
	for (int i = 0; i < case_num; ++ i)
	{
		long long radius, paint, count = 0;
		std::cin >> radius >> paint;
		while (paint > 0)
		{
			long long cost = 2 * radius + 1;
			if (cost > paint)
			{
				break;
			} else
			{
				++ count;
				radius += 2;
				paint -= cost;
			}
		}
		std::cout << "Case #" << i + 1 << ": " << count << std::endl;
	}

	return 0;
}
