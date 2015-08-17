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

	long long galleon0, sickle0, knut0, galleon1, sickle1, knut1, carry = 0;
	char tmp;
	std::cin >> galleon0 >> tmp >> sickle0 >> tmp >> knut0 >> galleon1 >> tmp >> sickle1 >> tmp >> knut1;
	knut0 += knut1;
	carry = knut0 / 29;
	knut0 %= 29;
	sickle0 += sickle1 + carry;
	carry = sickle0 / 17;
	sickle0 %= 17;
	galleon0 += galleon1 + carry;
	std::cout << galleon0 << "." << sickle0 << "." << knut0 << std::endl;

	return 0;
}
