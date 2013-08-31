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
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("../output.txt", "w", stdout);
#endif
#endif

	int exit_num, quest_num, quest1, quest2, sum = 0;
	std::vector<int> exit_vec;
	std::cin >> exit_num;
	exit_vec.push_back(0);
	for (int i = 0; i < exit_num; ++ i)
	{
		int tmp;
		std::cin >> tmp;
		sum += tmp;
		exit_vec.push_back(sum);
	}
	cin >> quest_num;
	int dist;
	for (int i = 0; i < quest_num; ++ i)
	{
		cin >> quest1 >> quest2;
		dist = exit_vec[quest2 - 1] - exit_vec[quest1 - 1];
		dist = (dist < 0) ? - dist : dist;
		std::cout << ( (dist < sum / 2) ? dist : sum - dist ) << std::endl;
	}

	return 0;
}
