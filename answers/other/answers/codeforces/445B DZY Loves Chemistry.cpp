//@type DSU
//@result 12965768	2015-09-12 00:18:40	zetta217	445B - DZY Loves Chemistry	GNU C++	Accepted	30 ms	0 KB
#include <iostream>
using namespace std;
#include <vector>

int find(int chemical, const vector<int> &dsu_list) {
	while (dsu_list[chemical] != chemical) {
		chemical = dsu_list[chemical];
	}
	return chemical;
}
int main() {
	int chemical_num(0);
	int react_num(0);
	while (cin >> chemical_num >> react_num) {
		vector<int> dsu_list;
		for (size_t i = 0; i < chemical_num; ++ i) {
			// cannot set to -1. maybe input dataset contains chemical 1 reacts with chemical 1
			dsu_list.push_back(i);
		}
		for (int i = 0; i < react_num; ++ i) {
			int chemical0(0), chemical1(0);
			cin >> chemical0 >> chemical1;
			int parent0 = find(chemical0 - 1, dsu_list);
			int parent1 = find(chemical1 - 1, dsu_list);
			dsu_list[parent0] = parent1;
		}
		// set number as LL
		long long danger(1LL << chemical_num);
		for (size_t i = 0; i < dsu_list.size(); ++ i) {
			if (dsu_list[i] == i) {
				danger >>= 1;
			}
		}
		cout << danger << endl;
	}
	return 0;
}