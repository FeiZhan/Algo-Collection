//@type simple, implementation
//@result 12795768	2015-09-01 03:55:23	zetta217	431B - Shower Line	GNU C++	Accepted	30 ms	0 KB

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	vector<vector<int> > happy_mat(5, vector<int> (5, 0));
	vector<int> stu_list;
	for (size_t i = 0; i < 5; ++ i) {
		stu_list.push_back(i);
		for (size_t j = 0; j < 5; ++ j) {
			cin >> happy_mat[i][j];
		}
	}
	int max_happy(0);
	do {
		int happy(0);
		int begin(1);
		while (begin < stu_list.size()) {
			for (size_t i = begin; i < stu_list.size(); i += 2) {
				happy += happy_mat[stu_list[i - 1]][stu_list[i]] + happy_mat[stu_list[i]][stu_list[i - 1]];
			}
			++ begin;
		}
		if (max_happy < happy) {
			max_happy = happy;
		}
	}
	// next permutation
	while (next_permutation(stu_list.begin(), stu_list.end()));
	cout << max_happy << endl;
	return 0;
}