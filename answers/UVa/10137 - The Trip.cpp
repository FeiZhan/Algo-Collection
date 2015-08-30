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

#include <iomanip>
#include <vector>

int main(int argc, char *argv[])
{
#ifdef _FILE_DEBUG_
	ifstream fin;
	fin.open("input.txt");
	cin.rdbuf(fin.rdbuf());
#ifdef _C_LAN_
	freopen("input.txt", "r", stdin);
#endif
#endif
#ifdef _FILE_DEBUG_
	ofstream fout;
	fout.open("output.txt");
	cout.rdbuf(fout.rdbuf());
#ifdef _C_LAN_
	freopen("output.txt", "w", stdout);
#endif
#endif

	size_t stu_num(0);
	while (cin >> stu_num && stu_num > 0) {
		vector<double> cost_list;
		double average = 0.0;
		for (size_t i = 0; i < stu_num; ++ i) {
			double cost;
			cin >> cost;
			average += cost;
			cost_list.push_back(cost);
		}
		average /= stu_num;
		double larger(0.0), smaller(0.0);
		for (size_t i = 0; i < cost_list.size(); ++ i) {
			if (cost_list[i] > average) {
				larger += static_cast<int> ((cost_list[i] - average) * 100.0) / 100.0;
			} else {
				smaller += static_cast<int> ((average - cost_list[i]) * 100.0) / 100.0;
			}
		}
		cout << setprecision(2) << fixed << showpoint << "$" << (larger > smaller ? larger : smaller) << endl;
	}

	return 0;
}
















