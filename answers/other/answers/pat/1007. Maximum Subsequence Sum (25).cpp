//
#include <iostream>
using namespace std;

#include <vector>

int main (int argc, char *argv[])
{
	int num_num(0);
	while (cin >> num_num) {
		vector<int> num_list;
		for (int i = 0; i < num_num; ++ i) {
			int num(0);
			cin >> num;
			num_list.push_back(num);
		}
		int sum(0), all_sum(0);
		size_t left(0), right(0), start(0), end(num_list.size() - 1);
		for (size_t i = 0; i < num_list.size(); ++ i) {
			if (sum < 0) {
				sum = 0;
				left = i;
			}
			sum += num_list[i];
			right = i;
			if (sum > all_sum || (0 == sum && num_list.size() == end + 1)) {
				all_sum = sum;
				start = left;
				end = right;
			}
		}
		cout << all_sum << " " << num_list[start] << " " << num_list[end] << endl;
	}

	return 0;
}
