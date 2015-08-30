// TLE
#include <cstdio>
#include <iostream>
using namespace std;

#include <vector>

int main (int argc, char *argv[]) {
	int num_num(0);
	while (cin >> num_num) {
		vector<int> num_list(num_num, 0);
		for (int i = 0; i < num_num; ++ i) {
			int num(0);
			//cin >> num;
			scanf("%d", &num);
			num_list[num] = i;
		}
		int count(0);
		int error(1);
		while (error) {
			for (size_t i = error; i < num_list.size(); ++ i) {
				if (i != num_list[i]) {
					error = i;
					break;
				}
			}
			if (0 == error) {
				break;
			}
			if (0 == num_list[0]) {
				num_list[0] = num_list[error];
				num_list[error] = 0;
				++ count;
			}
			while (num_list[0]) {
				int temp(num_list[num_list[0]]);
				num_list[num_list[0]] = num_list[0];
				num_list[0] = temp;
				++ count;
			}
		}
		cout << count << endl;
	}

	return 0;
}