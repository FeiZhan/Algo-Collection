//@type greedy, DP
//@result 12964986	2015-09-11 22:53:08	zetta217	534B - Covered Path	GNU C++	Accepted	15 ms	0 KB
// I don't use DP
#include <iostream>
using namespace std;

int main() {
	int begin(0);
	int end(0);
	while (cin >> begin >> end) {
		if (begin > end) {
			int temp = begin;
			begin = end;
			end = temp;
		}
		int time(0);
		int change(0);
		cin >> time >> change;
		int current(begin);
		int distance(begin);
		for (int i = 1; i + 1 < time; ++ i) {
			current = current + change;
			if (current > end && current - change * (time - 1 - i) > end) {
				current = end + change * (time - 1 - i);
			}
			distance += current;
			//cout << "test " << i << " " << current << " " << distance << endl;
		}
		cout << distance + end << endl;
	}
	return 0;
}