// mostly AC, one SF
#include <cstdio>
#include <iostream>
using namespace std;

#include <iomanip>
#include <vector>

double dfs(int current, double price, const vector<vector<int> > &mem_mat, const vector<int> &retail_list, const double increment) {
	double total(0.0);
	if (current >= mem_mat.size()) {
		return total;
	}
	for (size_t i = 0; i < mem_mat[current].size(); ++ i) {
		total += dfs(mem_mat[current][i], price * (1.0 + increment / 100.0), mem_mat, retail_list, increment);
	}
	total += price * retail_list[current];
	return total;
}
int main (int argc, char *argv[]) {
	int mem_num(0);
	double unit_price(0.0);
	double increment(0.0);
	while (cin >> mem_num >> unit_price >> increment) {
		vector<vector<int> > mem_mat(mem_num, vector<int> ());
		vector<int> retail_list(mem_num, 0);
		for (int i = 0; i < mem_num; ++ i) {
			int dist_num(0);
			cin >> dist_num;
			int prod_num(0);
			mem_mat[i].resize(dist_num, 0);
			if (0 == dist_num) {
				cin >> prod_num;
			}
			else {
				for (int j = 0; j < dist_num; ++ j) {
					int id(0);
					cin >> id;
					mem_mat[i][j] = id;
				}
			}
			retail_list[i] = prod_num;
		}
		cout << setiosflags(ios::fixed) << setprecision(1) << dfs(0, unit_price, mem_mat, retail_list, increment) << endl;
	}

	return 0;
}