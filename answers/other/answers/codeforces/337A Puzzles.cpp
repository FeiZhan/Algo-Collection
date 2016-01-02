//@type simple, two pointers
//@result 12874785	2015-09-06 19:07:09	zetta217	337A - Puzzles	GNU C++	Accepted	30 ms	0 KB
#include <iostream>
using namespace std;
#include <climits>
#include <vector>
#include <algorithm>

int main() {
	int stu_num(0);
	int puzzle_num(0);
	while (cin >> stu_num >> puzzle_num) {
		vector<int> puzzle_list;
		for (int i = 0; i < puzzle_num; ++ i) {
			int puzzle(0);
			cin >> puzzle;
			puzzle_list.push_back(puzzle);
		}
		sort(puzzle_list.begin(), puzzle_list.end());
		int min_diff(INT_MAX);
		for (size_t i = stu_num - 1; i < puzzle_list.size(); ++ i) {
			int diff(puzzle_list[i] - puzzle_list[i - stu_num + 1]);
			if (diff < min_diff) {
				min_diff = diff;
			}
		}
		cout << min_diff << endl;
	}
	return 0;
}