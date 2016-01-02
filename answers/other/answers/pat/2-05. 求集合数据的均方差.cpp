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

#include <cmath>
#include <iomanip>
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

	int data_num;
	double data, average, smr;
	std::vector<double> data_list;
	while (std::cin >> data_num)
	{
		data_list.clear();
		average = 0;
		for (int i = 0; i < data_num; ++ i)
		{
			std::cin >> data;
			average += data;
			data_list.push_back(data);
		}
		average /= data_num;
		smr = 0;
		for (int i = 0; i < data_num; ++ i)
		{
			smr += (data_list[i] - average) * (data_list[i] - average);
		}
		smr = sqrt(smr / data_num);
		std::cout << std::fixed << std::setprecision(5) << smr << std::endl;
	}

	return 0;
}
