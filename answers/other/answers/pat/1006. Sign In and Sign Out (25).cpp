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

#include <string>
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

	int len;
	std::vector<std::string> name;
	std::vector<int> in_hour, in_minute, in_second;
	std::vector<int> out_hour, out_minute, out_second;
	cin >> len;
	for (int i = 0; i < len; ++ i)
	{
		std::string tmp1;
		int tmp[6];
		char tmp2;
		cin >> tmp1 >> tmp[0] >> tmp2 >> tmp[1] >> tmp2 >> tmp[2] >> tmp[3] >> tmp2 >> tmp[4] >> tmp2 >> tmp[5];
		name.push_back(tmp1);
		in_hour.push_back(tmp[0]);
		in_minute.push_back(tmp[1]);
		in_second.push_back(tmp[2]);
		out_hour.push_back(tmp[3]);
		out_minute.push_back(tmp[4]);
		out_second.push_back(tmp[5]);
	}
	size_t in_min = 0, out_max = 0;
	for (int i = 0; i < len; ++ i)
	{
		if ( in_hour[i] < in_hour[in_min] || (in_hour[i] == in_hour[in_min] && in_minute[i] < in_minute[in_min]) || (in_hour[i] == in_hour[in_min] && in_minute[i] == in_minute[in_min] && in_second[i] < in_second[in_min]) )
		{
			in_min = i;
		}
		if ( out_hour[i] > out_hour[out_max] || (out_hour[i] == out_hour[out_max] && out_minute[i] > out_minute[out_max]) || (out_hour[i] == out_hour[out_max] && out_minute[i] == out_minute[out_max] && out_second[i] > out_second[out_max]) )
		{
			out_max = i;
		}
	}
	std::cout << name[in_min] << " " << name[out_max] << std::endl;

	return 0;
}
