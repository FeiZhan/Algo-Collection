// do not use string, map. They caused TLE
#include <iostream>
using namespace std;

#include <iomanip>

int main (int argc, char *argv[])
{
	int start[2];
	size_t node_num(0);
	while (cin >> start[0] >> start[1] >> node_num) {
		pair<int, bool> node_map[100000];
		for (size_t i = 0; i < node_num; ++ i) {
			int address, next;
			char letter('\0');
			cin >> address >> letter >> next;
			node_map[address] = make_pair(next, false);
		}
		while (start[0] >= 0) {
			node_map[start[0]].second = true;
			start[0] = node_map[start[0]].first;
		}
		bool find_flag(false);
		while (start[1] >= 0) {
			if (node_map[start[1]].second) {
				cout << setfill('0') << setw(5) << start[1] << endl;
				find_flag = true;
				break;
			}
			start[1] = node_map[start[1]].first;
		}
		if (! find_flag) {
			cout << -1 << endl;
		}
	}

	return 0;
}