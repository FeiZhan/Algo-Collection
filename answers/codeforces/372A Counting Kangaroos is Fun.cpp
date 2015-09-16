//@type two pointers
//@result 12965997	2015-09-12 00:52:47	zetta217	372A - Counting Kangaroos is Fun	GNU C++	Accepted	998 ms	3600 KB
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	int kan_num(0);
	while (cin >> kan_num) {
		vector<int> kan_list;
		for (int i = 0; i < kan_num; ++ i) {
			int kan(0);
			cin >> kan;
			kan_list.push_back(kan);
		}
		sort(kan_list.begin(), kan_list.end());
		int count(0);
		// note
		int j = (kan_list.size() - 1) / 2;
		int i = kan_list.size() - 1;
		while (i > (kan_list.size() - 1) / 2 && j >= 0) {
			if (kan_list[i] >= kan_list[j] * 2) {
				-- i;
				++ count;
				//cout << "test " << i << " holds " << j << endl;
			}
			-- j;
		}
		//count += j + 1 + i - kan_list.size() / 2;
		//cout << "test " << "rest " << i << " " << j << endl;
		cout << kan_num - count << endl;
	}
	return 0;
}