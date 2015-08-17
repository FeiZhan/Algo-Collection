//WA
#define _FILE_DEBUG_
//#define _C_LAN_
//#define _DEBUG_OUTPUT_
#ifdef _FILE_DEBUG_
#include <fstream>
#endif
#include <iostream>
#include <stdio.h>
using namespace std;

#include <cfloat>
#include <map>

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

	double max_capacity, max_dist;
	int average, station_num;
	cin >> max_capacity >> max_dist >> average >> station_num;
	std::map<double, double> price;
	double tmp1, tmp2;
	for (int i = 0; i < station_num; ++ i)
	{
		cin >> tmp1 >> tmp2;
		price.insert(std::make_pair(tmp2, tmp1));
	}
	double pos = 0.0, gas = 0.0, cost = 0.0;
	for (std::map<double, double>::iterator it = price.begin(); it != price.end(); ++ it)
	{
		if (pos + gas * average < it->first)
		{
			break;
		}
		gas -= (it->first - pos) / average;
		pos = it->first;
std::cout << "pos " << pos << " gas " << gas << std::endl;
		std::map<double, double>::iterator cheapest = it;
		double cheapest_gas = DBL_MAX;
		for (std::map<double, double>::iterator it2 = it; it2 != price.end() && gas * average >= it2->first - pos; ++ it2)
		{
			if (cheapest_gas > it2->second)
			{
				cheapest_gas = it2->second;
				cheapest = it2;
			}
		}
		double new_gas;
		if (cheapest == it)
		{
			std::map<double, double>::iterator it3 = it, cheapest = it;
			++ it3;
			cheapest = it3;
			double cheapest_gas = DBL_MAX;
			for (; it3 != price.end() && max_capacity * average >= it3->first - pos; ++ it3)
			{
				if (cheapest_gas > it3->second)
				{
					cheapest_gas = it3->second;
					cheapest = it3;
				}
			}
			new_gas = (cheapest->first - pos) / average;
			new_gas = (new_gas > max_capacity) ? max_capacity : new_gas;
			cost += (new_gas - gas) * it->second;
			gas = new_gas;
		} else
		{
			new_gas = (cheapest->first - pos) / average - gas;
			new_gas = (new_gas > 0.0) ? new_gas : 0.0;
			cost += new_gas * it->second;
			gas += new_gas;
		}
std::cout << "pos " << pos << " cheapest " << cheapest->first << " gas " << gas << " cost " << cost << " new_gas " << new_gas << std::endl;
	}
	if (pos + gas * average < max_dist)
	{
		std::cout << "The maximum travel distance = " << pos + gas * average << std::endl;
	} else
	{
		std::cout << cost << std::endl;
	}
	return 0;
}
