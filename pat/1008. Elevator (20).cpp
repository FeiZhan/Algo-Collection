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

	int len, request, pos = 0, time = 0;
	cin >> len;
	for (int i = 0; i < len; ++ i)
	{
		cin >> request;
		if (request >= pos)
		{
			time += 6 * (request - pos);
		} else
		{
			time += 4 * (pos - request);
		}
		time += 5;
		pos = request;
	}
	std::cout << time << std::endl;

	return 0;
}
