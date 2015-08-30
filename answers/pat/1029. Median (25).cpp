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
	//cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	long long len, tmp;
	std::vector<long long> seq[2];
	for (int i = 0; i < 2; ++ i)
	{
		std::cin >> len;
		for (long long j = 0; j < len; ++ j)
		{
			std::cin >> tmp;
			seq[i].push_back(tmp);
		}
	}
	for (long long i = 0, j = 0; i < seq[0].size() || j < seq[1].size();)
	{
		if ( i + j > (seq[0].size() + seq[1].size()) / 2 )
		{
			//std::cout << "error" << std::endl;
			break;
		}
		if ((j >= seq[1].size() || seq[0][i] < seq[1][j]) && i < seq[0].size())
		{
			++ i;
			if ( i + j == (seq[0].size() + seq[1].size()) / 2 )
			{
				std::cout << seq[0][i] << std::endl;
				break;
			}
		} else
		{
			++ j;
			if ( i + j == (seq[0].size() + seq[1].size()) / 2 )
			{
				std::cout << seq[1][j] << std::endl;
				break;
			}
		}
	}

	return 0;
}
