//@type two pointers
//@result 12875608	2015-09-06 20:36:14	zetta217	489B - BerSU Ball	GNU C++	Accepted	15 ms	0 KB
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
	int boy_num(0);
	while (cin >> boy_num) {
		vector<int> boy_list;
		for (int i = 0; i < boy_num; ++ i) {
			int boy(0);
			cin >> boy;
			boy_list.push_back(boy);
		}
		sort(boy_list.begin(), boy_list.end());
		vector<int> girl_list;
		int girl_num(0);
		cin >> girl_num;
		for (int i = 0; i < girl_num; ++ i) {
			int girl(0);
			cin >> girl;
			girl_list.push_back(girl);
		}
		sort(girl_list.begin(), girl_list.end());
		int count(0);
		for (size_t boy = 0, girl = 0; boy < boy_list.size() && girl < girl_list.size();) {
			int diff = boy_list[boy] - girl_list[girl];
			if (diff >= -1 && diff <= 1) {
				++ count;
				++ boy;
				++ girl;
			}
			else if (diff > 1) {
				++ girl;
			}
			else if (diff < -1) {
				++ boy;
			}
		}
		cout << count << endl;
	}
	return 0;
}