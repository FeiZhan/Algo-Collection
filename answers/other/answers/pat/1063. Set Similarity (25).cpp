//
#include <iostream>
using namespace std;

#include <iomanip>
#include <vector>
#include <algorithm>

int main (int argc, char *argv[])
{
	int set_num(0);
	while (cin >> set_num) {
		vector<vector<int> > set_list;
		for (int i = 0; i < set_num; ++ i) {
			int num_num(0);
			cin >> num_num;
			vector<int> num_list;
			for (int i = 0; i < num_num; ++ i) {
				int num;
				cin >> num;
				num_list.push_back(num);
			}
			sort( num_list.begin(), num_list.end() );
			num_list.erase( unique( num_list.begin(), num_list.end() ), num_list.end() );
			set_list.push_back(num_list);
		}
		int query_num(0);
		cin >> query_num;
		for (int i = 0; i < query_num; ++ i) {
			int query[2];
			for (size_t j = 0; j < 2; ++ j) {
				cin >> query[j];
			}
			vector<int> set_union(set_list[query[0] - 1].size() + set_list[query[1] - 1].size(), 0);
			// use vector instead because of TLE
			merge(set_list[query[0] - 1].begin(), set_list[query[0] - 1].end(), set_list[query[1] - 1].begin(), set_list[query[1] - 1].end(), set_union.begin());
			sort( set_union.begin(), set_union.end() );
			set_union.erase( unique( set_union.begin(), set_union.end() ), set_union.end() );
			double similarity = 1.0 * (set_list[query[0] - 1].size() + set_list[query[1] - 1].size() - set_union.size()) / set_union.size();
			cout << fixed << setprecision(1) << similarity * 100.0 << "%" << endl;
			//cout << "test " << set_list[query[0] - 1].size() << set_list[query[1] - 1].size() << set_union.size() << endl;
		}
	}

	return 0;
}