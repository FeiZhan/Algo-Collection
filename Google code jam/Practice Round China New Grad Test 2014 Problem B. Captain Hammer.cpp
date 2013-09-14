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
	double speed, distance;
	for (int i = 0; i < case_num; ++ i)
	{
		std::cin >> speed >> distance;
		std::cout << "Case #" << i + 1 << ": " << std::fixed << std::setprecision(7) << asin(9.8 * distance / speed / speed) / M_PI * 180.0 / 2.0 << std::endl;
	}

	return 0;
}
