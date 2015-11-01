//149B	 Martian Clock (not submitted)
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
	fin.open("./input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("./input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("./output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("./output.txt", "w", stdout);
#endif
#endif

	string time_str;
	vector<int> hour, minute;
	int pos, min_radix, tmp, hour_int, min_int;
	bool leading_flag[2], is_first, if_found;
	while (cin >> time_str)
	{
		pos = time_str.find(':');
		hour.clear();
		minute.clear();
		min_radix = 0;
		leading_flag[0] = true;
		for (int i = 0; i < pos; ++ i)
		{
			if (leading_flag[0] && time_str.at(i) == '0')
				continue;
			else
				leading_flag[0] = false;
			if (time_str.at(i) >= '0' && time_str.at(i) <= '9')
				tmp = static_cast<int>(time_str.at(i) - '0');
			else
				tmp = static_cast<int>(time_str.at(i) - 'A') + 10;
			if (tmp > min_radix)
			{
				min_radix = tmp;
			}
			hour.push_back(tmp);
		}
		leading_flag[1] = true;
		for (size_t i = pos+1; i < time_str.size(); ++ i)
		{
			if (leading_flag[1] && time_str.at(i) == '0')
				continue;
			else
				leading_flag[1] = false;
			if (time_str.at(i) >= '0' && time_str.at(i) <= '9')
				tmp = static_cast<int>(time_str.at(i) - '0');
			else
				tmp = static_cast<int>(time_str.at(i) - 'A') + 10;
			if (tmp > min_radix)
			{
				min_radix = tmp;
			}
			minute.push_back(tmp);
		}
		if (hour.size() == 1 && hour.at(0) < 24 && minute.size() == 1 && minute.at(0) < 60)
		{
			cout << -1 << endl;
			continue;
		}
		if (hour.size() == 0 && minute.size() == 0)
		{
			cout << -1 << endl;
			continue;
		}
		if (hour.size() == 0 && minute.size() == 1 && minute.at(0) < 60)
		{
			cout << -1 << endl;
			continue;
		}
		if (hour.size() == 1 && hour.at(0) < 24 && minute.size() == 0)
		{
			cout << -1 << endl;
			continue;
		}
		is_first = true;
		for (size_t i = min_radix + 1; i < 100; ++ i)
		{
			hour_int = 0;
			if_found = false;
			for (size_t j = 0; j < hour.size(); ++ j)
			{
				hour_int = hour_int * i + hour.at(j);
				if (i == min_radix + 1 && hour_int >= 24)
				{
					cout << 0;
					if_found = true;
					break;
				}
			}
			if (if_found)
				break;
			//cout << "hour_int " << hour_int << endl;
			min_int = 0;
			for (size_t j = 0; j < minute.size(); ++ j)
			{
				min_int = min_int * i + minute.at(j);
				if (i == min_radix + 1 && min_int >= 60)
				{
					cout << 0;
					if_found = true;
					break;
				}
			}
			if (if_found)
				break;
			//cout << "min_int " << min_int << endl;
			if (hour_int < 24 && min_int < 60)
			{
				if (is_first)
				{
					is_first = false;
				} else
				{
					cout << " ";
				}
				cout << i;
			}
		}
		cout << endl;
	}

	return 0;
}

