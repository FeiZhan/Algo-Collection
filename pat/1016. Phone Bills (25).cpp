// Partly WA
// compute the entire charge between two days, and subtract to hour and minute

#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
struct Record
{
	std::string name;
	int month, day, hour, minute;
	std::string status;
	Record(const std::string &n, int m, int d, int h, int mi, const std::string &s) : name(n), month(m), day(d), hour(h), minute(mi), status(s)
	{}
};
bool compare(const Record &r0, const Record &r1)
{
	if (r0.name != r1.name)
	{
		return r0.name < r1.name;
	}
	else if (r0.month != r1.month)
	{
		return r0.month < r1.month;
	}
	else if (r0.day != r1.day)
	{
		return r0.day < r1.day;
	}
	else if (r0.hour != r1.hour)
	{
		return r0.hour < r1.hour;
	}
	else if (r0.minute != r1.minute)
	{
		return r0.minute < r1.minute;
	}
	else if (r0.status != r1.status)
	{
		return r0.status < r1.status;
	}
	return false;
}

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

	int toll_list[24], allday = 0;
	for (int i = 0; i < 24; ++ i)
	{
		std::cin >> toll_list[i];
		allday += toll_list[i] * 60;
	}
	int record_num;
	std::cin >> record_num;
	int month, day, hour, minute;
	char tmp;
	std::string name, status;
	std::vector<Record> record_list;
	for (int i = 0; i < record_num; ++ i)
	{
		//CYLL 01:01:06:01 on-line, mm:dd:hh:mm
		std::cin >> name >> month >> tmp >> day >> tmp >> hour >> tmp >> minute >> status;
		record_list.push_back(Record(name, month, day, hour, minute, status));
	}
	std::sort(record_list.begin(), record_list.end(), compare);
	name.clear();
	month = 0;
	int charge, all_charge = 0;
	for (size_t i = 1; i < record_list.size(); ++ i)
	{
		if (name != record_list[i].name)
		{
			if (1 < i)
			{
				std::cout << "Total amount: $" << std::fixed << std::setprecision(2) << static_cast<double>(all_charge) / 100.0 << std::endl;
				all_charge = 0;
			}
			name = record_list[i].name;
			month = record_list[i].month;
			std::cout << name << (month < 10 ? " 0" : " ") << month << std::endl;
		}
		if (month != record_list[i].month)
		{
			if (1 < i)
			{
				std::cout << "Total amount: $" << std::fixed << std::setprecision(2) << static_cast<double>(all_charge) / 100.0 << std::endl;
				all_charge = 0;
			}
			month = record_list[i].month;
			std::cout << (month < 10 ? "0" : "") << month << std::endl;
		}
		if ("off-line" == record_list[i].status && "on-line" == record_list[i - 1].status)
		{
			//01:05:59 01:07:00 61 $12.10
			std::cout << (record_list[i - 1].day < 10 ? "0" : "") << record_list[i - 1].day << (record_list[i - 1].hour < 10 ? ":0" : ":") << record_list[i - 1].hour << (record_list[i - 1].minute < 10 ? ":0" : ":") << record_list[i - 1].minute << " ";
			std::cout << (record_list[i].day < 10 ? "0" : "") << record_list[i].day << (record_list[i].hour < 10 ? ":0" : ":") << record_list[i].hour << (record_list[i].minute < 10 ? ":0" : ":") << record_list[i].minute << " ";
			std::cout << (record_list[i].day - record_list[i - 1].day) * 24 * 60 + (record_list[i].hour - record_list[i - 1].hour) * 60 + record_list[i].minute - record_list[i - 1].minute;
			charge = (record_list[i].day - record_list[i - 1].day + 1) * allday;
			for (int j = 0; j < record_list[i - 1].hour; ++ j)
			{
				charge -= toll_list[j] * 60;
			}
			charge -= toll_list[ record_list[i - 1].hour ] * record_list[i - 1].minute;
			for (int j = record_list[i].hour + 1; j < 24; ++ j)
			{
				charge -= toll_list[j] * 60;
			}
			charge -= toll_list[ record_list[i].hour ] * (60 - record_list[i].minute);
			std::cout << " $" << std::fixed << std::setprecision(2) << static_cast<double>(charge) / 100.0 << std::endl;
			all_charge += charge;
		}
	}
	std::cout << "Total amount: $" << std::fixed << std::setprecision(2) << static_cast<double>(all_charge) / 100.0 << std::endl;

	return 0;
}
