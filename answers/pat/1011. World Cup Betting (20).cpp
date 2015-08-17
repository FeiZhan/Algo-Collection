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

#include <climits>
#include <iomanip>

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

	double odd[3];
	int select[3];
	const char CHOICE[3] = {'W', 'T', 'L'};
	for (int i = 0; i < 3; ++ i)
	{
		odd[i] = INT_MIN;
		for (int j = 0; j < 3; ++ j)
		{
			double tmp;
			cin >> tmp;
			if (odd[i] < tmp)
			{
				odd[i] = tmp;
				select[i] = j;
			}
		}
		std::cout << CHOICE[select[i]] << " ";
	}
	std::cout << std::fixed << std::setprecision(2) << (odd[0] * odd[1] * odd[2] * .65 - 1.0) * 2 << std::endl;

	return 0;
}
