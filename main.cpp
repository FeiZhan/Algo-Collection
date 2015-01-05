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

	double capacity, distance, dist_gas;
	size_t gas_num;
	while (cin >> capacity >> distance >> dist_gas >> gas_num) {
		vector<double> price_list;
		vector<double> dist_list;
		for (size_t i = 0; i < gas_num; ++ i) {
			double price, dist;
			cin >> price >> dist;
			price_list.push_back(price);
			dist_list.push_back(dist);
		}
		if (0 == gas_num) {
			if (capacity * dist_gas >= distance) {
				cout << 0.0 << endl;
			} else {
				cout << "The maximum travel distance = " << capacity * dist_gas << endl;
			}
		} else {
			double gas_total = capacity - dist_list[0] / dist_gas, cost_total = 0.0;
			size_t current = 0;
			while (dist_list[current] <= distance && current + 1 < gas_num) {
				if (gas_total * dist_gas < dist_list[current + 1] - dist_list[current]) {
					cout << "The maximum travel distance = " << dist_list[current] + gas_total * dist_gas << endl;
					break;
				}
				else if (gas_total * dist_gas >= distance - dist_list[current]) {
					cout << cost_total << endl;
					break;
				}
				else {
					size_t next = current;
					for (size_t i = current + 1; i < gas_sum; ++ i) {
						if (price_list[i] < price_list[current]) {
							next = i;
							break;
						}
					}
					if (next == current) {
						cost_total += (capacity - gas_total) * price_list[current];
					} else {
						double new_gas = (dist_list[next] - dist_list[current]) / dist_gas;
						if (new_gas + gas_total > capacity) {
							new_gas = capacity - gas_total;
						}
						gas_total += new_gas;
						cost_total += new_gas * 
					}
				}
				++ current;
			}
		}
	}

	return 0;
}




